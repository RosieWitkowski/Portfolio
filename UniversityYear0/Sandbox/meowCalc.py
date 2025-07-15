BIGNUMBER = 10

def main():
    # SETTINGS
    print("Would you like to enter cat mode? 1 for Yes, 2 for No.")
    confirm = getIntInput(1,2)


    # GET NUMBERS TO COMPUTE
    print("Number 1:")
    n1 = getIntInput(0,9999999999999999999999999999999999999999999999999)
    print("Number 2:")
    n2 = getIntInput(0,9999999999999999999999999999999999999999999999999)

    # GET OPERATION TO COMPLETE
    print("Please select an operation to complete:\n1 - Add\n2 - Multiply\n3 - Divide\n4 - Mod")
    operation = getIntInput(1,4)

    # CALCULATE OPERATION ON THE NUMBERS
    ans = calculate(n1, n2, operation)

    # DISPLAY ANSWER
    if confirm == 1:
        print(f"{ans} cats are coming!")
        meow(ans)
    else:
        print(f"Answer: {ans}")
    

def getIntInput(min, max):
    n = input()
    try:
        while (not n.isnumeric()) or (int(n) < min) or (int(n) > max):
            print(f"Please provide a number between {min} and {max}, in number format (1, 2, 3, 4, etc. NOT one, two, three...): ")
            n = input()
    except ValueError:
        print("Invalid input provided. Please try again.")
    return int(n)


def calculate(n1, n2, operation):
    if operation == 1:
        # Add
        return n1+n2
    elif operation == 2:
        #Multiply
        return n1*n2
    elif operation == 3:
        # Divide
        return n1/n2
    else:
        # Mod
        return n1%n2


def meow(n):
    for i in range(int(n)):
        print("Meow! =^w^=")
    return 1

if __name__ == "__main__":
    main()