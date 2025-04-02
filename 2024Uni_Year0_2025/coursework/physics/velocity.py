def main():
    """Calculates the average velocity of an object, given its distance traveled and time taken."""

    distance, time = validate_int("Distance: "), validate_int("Time: ")
    # Prevents zero division error
    while time < 1:
        validate_int("Time (must not be zero): ")

    # Converts units to metres and seconds, as required by the velocity formula    
    try:
        distance, time = convert_units(distance, time)
    except TypeError:
        print("Units not found.")
        exit()

    avg_velocity = calculateVelDispl(distance, time) # m/s
    print(f"The man ran {distance} metres, in {time} seconds. His average velocity was {avg_velocity} m/s.")
    return 1

def calculateVelDispl(distance, time):
    # Average velocity, in m/s
    return distance / time 

def validate_int(text):
    """
    Attempts to typecast a requested input to float, exits if there is an exception.

    Args: 
        text (string): Used in input() to specify what value is being requested.

    Returns:
        float: the typecasted value.
    """
    value = input(text)

    try: 
        value = float(value)
    except ValueError:
        print("Please provide numbers only.")
        exit()
    
    return float(value)

def convert_units(distance, time):
    """Uses dictionaries to convert between a few potential units for distance and time, returning either the converted values or False if units not listed."""
    units_distance, units_time = input("Units for distance: ").lower(), input("Units for time: ").lower()[:3]

    distance_conversions = {
        'centimeter': -3,
        'cm': -3,
        'kilometer': 3,
        'km': 3
    }
    
    time_conversions = {
        'min': 60,
        'hou': (60 * 60),
        'hrs': (60 * 60),
        'day': (60 * 60 * 24)
    }

    if units_distance != 'm':
        if units_distance in distance_conversions:
            distance *= 10 **(distance_conversions[units_distance])
        else:
            return False
    if units_time != 's':
        if units_time in time_conversions:
            time *= time_conversions[units_time]
        else:
            print(units_time)
            return False
        
    return distance, time

if __name__ == "__main__":
    main()