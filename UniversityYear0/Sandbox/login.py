
def main():
    # User database
    users = {
        "sally04" : {
            "id" : 14581458,
            "password" : "login32"
        },
        "brysonBrittle" : {
            "id" : 32123212,
            "password" : "password12345"
        },
        "rainBoom" : {
            "id" : 89368936,
            "password" : "dashIsCool123"
        }
    }

    # Find user
    user, password = None, None 

    while user not in users:
        user = input("Enter an existing username: ") 

    # Validate password
    wrong = 0

    while password != users[user]["password"]:
        password = input("Password: ")
        # Max 3 attempts
        wrong += 1
        if wrong == 3:
            print("Too many failed attempts.")
            exit()


    # Tailored message
    print(f"Login successfull, {user}!")

if __name__ == "__main__":
    main()