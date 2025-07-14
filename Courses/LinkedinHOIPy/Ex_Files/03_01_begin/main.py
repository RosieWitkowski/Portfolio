import csv
from pprint import pprint

EINSTEIN_CSV = 'Albert,Einstein,1879-03-14,1955-04-18,Germany,"for his services to Theoretical Physics, and especially for his discovery of the law of the photoelectric effect",physics,1921'

# Dict (similiar to a JSON)
EINSTEIN = {
    "birthplace": "Germany",
    "name": "Albert",
    "surname": "Einstein",
    "born": "1879-03-14",
    "category": "physics",
    "motivation": "for his services to Theoretical Physics...",
}

with open("laureates.csv", "r") as f: # with to atuomatically close, read mode to prevent accidental changes
    reader = csv.DictReader(f)
    laureates = list(reader)

# First 5
print(f"unformatted: \n {laureates[:5]}")
pprint(f"formatted: \n {laureates[:5]}")

for laureate in laureates:
    if laureate["surname"] == "Einstein":
        pprint(laureate)
        break
