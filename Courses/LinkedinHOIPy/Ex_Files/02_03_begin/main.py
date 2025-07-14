NAMES = ["John", "Paul", "George", "Ringo"]
AGES = [20, 21, 22, 23]

JOHN = NAMES[0] # First element due to zero index
PAUL = NAMES[1] # Second element

JOHN_PAUL = NAMES[:2] # Start, stop (beggining to index 1)
GEORGE_RINGO = NAMES[2:] # Start, stop (index 2 to end)
REVERSE = NAMES[::-1] # Start, stop, step (all, all, reverse)
EVERY_OTHER = NAMES[::2] # Start, stop, step (all, all, skip)

# List methods
print(sum(AGES))
print(min(AGES))
print(max(AGES))

# Prints as a list as they are units of list items, rather than concatonations of strings
print(JOHN_PAUL)
print(GEORGE_RINGO)
print(REVERSE)

string_example = "Hi, welcome to the codespace!"
print(string_example[:3])
