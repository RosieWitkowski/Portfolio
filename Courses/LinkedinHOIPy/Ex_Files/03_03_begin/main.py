import csv
import json
from pprint import pprint

EINSTEIN = {
    "birthplace": "Germany",
    "name": "Albert",
    "surname": "Einstein",
    "born": "1879-03-14",
    "category": "physics",
    "motivation": "for his services to Theoretical Physics...",
}

einstein_json = json.dumps(EINSTEIN)
back_to_dict = json.loads(einstein_json)
print(einstein_json)
pprint(back_to_dict)

with open("laureates.csv", "r") as f:
    reader = csv.DictReader(f)
    laureates = list(reader)


with open("laureates.json", "w") as f: # Write mode, creates a JSON file
    json.dump(laureates, f, indent=2) # Note that dumps is dump here (and loads would be load)
