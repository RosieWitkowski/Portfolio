from math import pow as power

def main():
    """Displays the depth and velocity of an object, given the time to fall a completed depth"""
    time, GRAVITY = validate_int("Time: "), -9.81 # m/s^2

    # Converts units to seconds
    time = convert_units(time)
    if time == False:
        print("Units not found")
        exit()
    
    # Applies formulas for depth and velocity
    depth, velocity = findWellDepth(time, GRAVITY) # m, m/s
    print(f"The well has a depth of {depth:e} metres. The coin takes {time} seconds to fall, so it had a final velocity of {velocity:e} m/s.")
    return 1

def findWellDepth(time, GRAVITY):
    """Returns the depth and velocity, respectively, using 'h = 1/2 x g x t^2' and 'v = gt'."""
    return (0.5 * - GRAVITY * power(time, 2)), (GRAVITY * time)

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

def convert_units(time):
    """Uses dictionaries to convert between a few potential units for and time, returning either the converted value or False if units not listed."""
    units_time = input("Units for time: ").lower()[:3]
    
    time_conversions = {
        'min': 60,
        'hou': (60 * 60),
        'hrs': (60 * 60),
        'day': (60 * 60 * 24)
    }

    if units_time != 's' and units_time != "seconds":
        if units_time in time_conversions:
            time *= time_conversions[units_time]
        else:
            return False
        
    return time

if __name__ == "__main__":
    main()