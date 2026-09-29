from sys import exit

menu = {
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}

items = set()
while (True):
    try:
        item = input("Item: ").title()
        if item in menu:
            items.add(item)

        for i in items:
            print(f"Item: {i}")
            print(f"Price: {menu[i]:0.2f}")

    # Exit if user types ctrl d
    except EOFError:
        print("Exited.")
        exit()


