# import libraries
import sys
from pyfiglet import Figlet

# get a figlet from module figlet
figlet = Figlet()

font = None

# set font based on command line arguments
if len(sys.argv) == 1:
    font = 'slant'
elif len(sys.argv) == 3 and (sys.argv[1] == '-f' or sys.argv[1] == '--font'):
    if sys.argv[2] in figlet.getFonts():
        font = sys.argv[2]
    else:
        sys.exit("Invalid command line arguments.")
else:
    sys.exit("Invalid command line arguments.")


# assign font
figlet.setFont(font= font)

# output text
s = input("Text: ")
print(figlet.renderText(s))