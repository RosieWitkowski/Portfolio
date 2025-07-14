import csv 
import json
from pprint import pprint

GRIAN = {
    "content": "minecraft",
    "name": "charles"
}

# JSON and dict formats
grian_json = json.dumps(GRIAN)
grian_dict = json.loads(grian_json)
print(grian_json)
pprint(grian_dict)

# Open CSV, get tubers list
with open("myExample.csv", "r") as f:
  reader = csv.DictReader(f)
  tubers = list(reader)

# Create JSON file
with open("myExample.json", "w") as f:
  json.dump(tubers, f, indent = 2)