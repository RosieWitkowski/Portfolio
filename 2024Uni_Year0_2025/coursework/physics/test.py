gravity_menu = {
    "Ear": 9.81,
    "Mer": 0.384,
    "Ven": 0.907,
    "Ear": 1,
    "Moo": 0.166,
    "Mar": 0.377,
    "Jup": 2.36, 
    "Sat": 0.916,
    "Ura": 0.889,
    "Nep": 1.12,
    "Plu": 0.071
}

planet = "Apple"
while planet not in gravity_menu:
    planet = input("Planet: ")[:3].capitalize()