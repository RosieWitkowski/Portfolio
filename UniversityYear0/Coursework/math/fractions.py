def main():
    """Prints either the addition or multiplication of two fractions, depending on the user's selection."""
    # Converts input into a tuple (seperated by numerator/denominator), then converts each element into an int
    fraction1, fraction2 = input("Fraction 1: ").split("/"), input("Fraction 2: ").split("/")
    a, c = int(fraction1[0]), int(fraction2[0])

    # Checks for denominator, else assumes whole number
    if len(fraction1) > 1:
        b = int(fraction1[1])
    else:
        b = 1
    if len(fraction2) > 1:
        d = int(fraction2[1])
    else:
        d = 1

    # Allows user to select add or multiply
    settings = ['A', 'M']
    setting = 'C'
    while setting not in settings:
        setting = input("What action would you like to perform?\n- Add\n- Multiply\n")[:1].upper()

    # Performs selected action
    if setting == 'A':
        ans = add_fractions(a, b, c, d)
    else:
        ans = multiply_fractions(a, b, c, d)

    # Improper fractions
    numerator, denominator = ans[0], ans[1]
    if denominator == 1:
        return print(f"Answer: {numerator}")

    if numerator > denominator:
        numerator, denominator = convert_mixed(numerator, denominator)


    # Final answer
    return print(f"Answer: {numerator}/{denominator}")

# Adds two fractions
def add_fractions(a, b, c, d):
    numerator, denominator = ((a * d) + (b * c)), (b * d)
    return simplify_fractions(numerator, denominator)

# Multiplies two fractions
def multiply_fractions(a, b, c, d):
    numerator, denominator = (a * c), (b * d)
    return simplify_fractions(numerator, denominator)

# Simplifies two fractions, using GCD
def simplify_fractions(numerator, denominator):
    gcd_value = gcd(numerator, denominator)
    numerator, denominator = (numerator // gcd_value), (denominator // gcd_value)
    return (numerator, denominator)

# Greatest Common Divisor (GCD)
def gcd(x, y):
    while y:
        x, y = y, x % y
    return x

# Tests for improper fraction and converts to mixed, if desired
def convert_mixed(numerator, denominator):
    # Select option
    print("Show as a mixed number?")
    confirms = ["Y", "N"]
    confirm = 'A'
    while confirm not in confirms: 
        confirm = input("Yes/No: ")[:1].upper()

    # Perform operation
    if confirm == "Y":
        numerator, mixed = (numerator // denominator), (numerator % denominator)
        numerator = str(numerator) + " and " + str(mixed)

    return numerator, denominator


if __name__ == "__main__":
    main()