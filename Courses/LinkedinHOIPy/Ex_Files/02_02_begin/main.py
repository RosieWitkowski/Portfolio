greet = "Hello World"
extened_grt = "Hello World, " + "this is a long string"

name = "John"

intrupution = f"Hello {name}"

greet_format = "Hello {}"

formatted = greet_format.format(name)

print(intrupution, formatted)

personalized_format = "Hi, {}! This is {} speaking. Welcome to {}!"
print(personalized_format.format(name, "Who?", "the codespace").replace('Who?', 'Rosie'))
