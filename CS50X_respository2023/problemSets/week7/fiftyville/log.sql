-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Assessing what information I can access
.tables

-- Gaining information on crime scene
.schema crime_scene_reports
SELECT description FROM crime_scene_reports
    WHERE
        year = 2021 AND
        month = 7 AND
        day = 28 AND
        street = "Humphrey Street";
-- Information found: TIME was 10:15 AM, Location was the BAKERY. There are interviews of 3 WITNESSES. Litterring at 16:36 wih no witnesses.

-- Gaining information on the scene of the crime
.schema bakery_security_logs

SELECT hour, minute, activity, license_plate FROM bakery_security_logs
    WHERE
        year = 2021 AND
        month = 7 AND
        day = 28 AND
        hour > 8 AND hour < 12
        ORDER BY hour, minute;

-- Gaining information from interviews
.schema interviews

SELECT name, transcript FROM interviews
    WHERE year = 2021 AND month = 7 AND day = 28;

-- Information: Male, German accent? Possibly transcript from seperate event as seems unrelated.
-- Information that seems related:
    -- Within ten minutes of theft (at 10:15 AM), thief got into car in bakery parking lot and left.
    -- Before the time Eugene arrived at emma's baskey, earlier in day, thief withdrew money from ATM on Legget Street.
    -- At time thief left bakery, called someone for less than a minute. Earliest flight the next day. Accomplice purchased ticket.
    -- Lily's sons are in Paris, which is far from fiftyville.

-- If the thief left the bakery within ten minutes I want to look at the bakery security camera again.
SELECT hour, minute, activity, license_plate FROM bakery_security_logs
    WHERE
        year = 2021 AND
        month = 7 AND
        day = 28 AND
        hour = 10 AND minute < 30
        ORDER BY hour, minute;
-- Cars that left within ten minutes of 10:15 =
    -- "5P2BI95", "94KL13X", "6P58WS2", "4328GD8", "G412CB7", "L93JTIZ", "322W7JE", "0NTHK55"

-- The thief withdrew money, earlier in the morning, ATM on leggett street.
.schema atm_transactions

SELECT id, account_number, amount FROM atm_transactions
    WHERE year = 2021 AND month = 7 AND day = 28
    AND atm_location = "Leggett Street"
    AND transaction_type = "withdraw";


-- At time thief left bakery, called someone for less than a minute. Earliest flight the next day. Accomplice purchased ticket.
.schema phone_calls
SELECT id, caller, receiver FROM phone_calls
    WHERE year = 2021 AND month = 7 AND day = 28
    AND duration < 60;
.schema airports

-- Find overlap to get person
.schema people
SELECT * FROM people
    WHERE phone_number IN
    (
    SELECT caller FROM phone_calls
        WHERE year = 2021 AND month = 7 AND day = 28
        AND duration < 60
    )
    AND
    license_plate IN
    (
        SELECT license_plate FROM bakery_security_logs
        WHERE
            year = 2021 AND
            month = 7 AND
            day = 28 AND
            hour = 10 AND minute < 30
    );
-- RESULT: 4 possible suspects: Sofia, Diana, Kelsey, Bruce.

-- Looking at bank accounts
.schema bank_accounts


SELECT person_id FROM bank_accounts
    WHERE account_number IN
    (
        SELECT account_number FROM atm_transactions
            WHERE year = 2021 AND month = 7 AND day = 28
            AND atm_location = "Leggett Street"
            AND transaction_type = "withdraw"
    );

-- Combining

SELECT * FROM people
    WHERE phone_number IN
    (
    SELECT caller FROM phone_calls
        WHERE year = 2021 AND month = 7 AND day = 28
        AND duration < 60
    )
    AND
    license_plate IN
    (
        SELECT license_plate FROM bakery_security_logs
        WHERE
            year = 2021 AND
            month = 7 AND
            day = 28 AND
            hour = 10 AND minute < 30
    )
    AND id IN
    (
        SELECT person_id FROM bank_accounts
            WHERE account_number IN
            (
                SELECT account_number FROM atm_transactions
                    WHERE year = 2021 AND month = 7 AND day = 28
                    AND atm_location = "Leggett Street"
                    AND transaction_type = "withdraw"
            )
    );
-- Results: Narrowed down to Diana or Bruce
-- (770) 55-1861
-- (367) 555-5533

-- Looking at flights for tomorrow
.schema flights

SELECT id, destination_airport_id, hour, minute FROM flights
    WHERE year = 2021 AND month = 7 AND day = 29
    AND origin_airport_id =
    (
        SELECT id FROM airports
        WHERE city = "Fiftyville"
    );

-- Results: There are 5 outbound at airport, the next day

-- Finding locations
SELECT  * FROM airports
    WHERE id IN
    (
        SELECT destination_airport_id FROM flights
        WHERE
        year = 2021 AND month = 7 AND day = 29
        AND origin_airport_id IN
        (
            SELECT id FROM airports
            WHERE city = "Fiftyville"
        )
    );
-- Chicago, New York City, Boston, Tokyo, San Francisco

-- Looking at planes
SELECT * FROM passengers
    WHERE passport_number =
    (
        SELECT passport_number FROM people
        WHERE name = "Bruce"
    );
    -- Result = flight_id 36 passport nunber 5773159633 seat 4A

SELECT * FROM passengers
    WHERE passport_number =
    (
        SELECT passport_number FROM people
        WHERE name = "Diana"
    );
    -- Result = flight_id 18, 23, 54 passport number 3592750733 seat 4C, 2C, 6C


-- Get reciever of phone call
-- (770) 55-1861
-- (367) 555-5533

-- DIANA
SELECT * FROM phone_calls
    WHERE caller = "(770) 555-1861"
    AND year = 2021 AND month = 7 AND day = 28 AND duration < 60;
    -- Result: only one reciever, (725) 555-3243 with ID 255

-- BRUCE
SELECT * FROM phone_calls
    WHERE caller = "(367) 555-5533"
    AND year = 2021 AND month = 7 AND day = 28 AND duration < 60;
    -- Result: only one reciever, (375) 555-8161 with id 233

SELECT * FROM people
    WHERE phone_number = "(725) 555-3243";
    -- Philip, passport = 3391710505
SELECT * FROM people
    WHERE phone_number = "(375) 555-8161";
    -- Robin, passport = NULL

-- THEREFORE
-- Either Diana with accomplice Philip
-- OR Bruce with accomplice Robin

SELECT * FROM passengers
    WHERE passport_number = 3391710505;



-- Diana passport number = 3592750833

-- Bruce passport number = 5773159633

-- Philip passport number = 3391710505

-- Robin passport number = NULL

-- Airport id for next day: 1, 4, 6, 9, 11

-- Using Bruce's passport number = flight id 36, seat 4A
SELECT * FROM passengers WHERE passport_number = 5773159633;
-- Using Philip's passport number = flight id 10, 28, 47 with seats 2A, 2A and 4D

-- Flight id available: 18, 23, 36, 43, 53
-- Bruce is the only one with a flight id in the available
-- Bruce with accomplice Philip, on flight 36

SELECT * FROM flights
    WHERE origin_airport_id =
    (
        SELECT id FROM airports
        WHERE city = "Fiftyville"
    )
    AND id = 36;
-- Result: destination_airport_id = 4
SELECT * FROM airports WHERE id = 4;
-- Result: New York City


SELECT * FROM phone_calls
    WHERE caller =
    (
        SELECT phone_number FROM people
        WHERE name = "Bruce"
    )
    AND year = 2021 AND month = 7 AND day = 28 AND duration < 60;

SELECT name FROM people
    WHERE phone_number =
    (
        SELECT receiver FROM phone_calls
            WHERE caller =
            (
                SELECT phone_number FROM people
                WHERE name = "Bruce"
            )
            AND year = 2021 AND month = 7 AND day = 28 AND duration < 60
    );

-- Bruce with accomplice Robin
-- Note that at some point I mixed Robin and Philip but looking at phone calls reminded me that it is Robin, not Philip
