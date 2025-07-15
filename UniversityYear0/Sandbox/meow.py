BIGNUMBER = 10

def main():
    n = getInput()
    meow(n)

def getInput():
    n = input("Number of cats: ")
    try:
        while (not n.isnumeric()) or (int(n) < 0):
            n = int(input("Please provide a positive number of cats, in number format - such as 2, 3, 5, etc.: "))
    except ValueError:
        print("Invalid input provided. Please try again.")
    return int(n)

def meow(n):
    if n == 0:
        print("- it's quiet here! - ")
    elif n > BIGNUMBER:
        print("- there's cat hairs in my sandwhich, gross! -")
    else:
        print("- here they come! -")

    for i in range(n):
        print("Meow! =^w^=")
    return 1

if __name__ == "__main__":
    main()