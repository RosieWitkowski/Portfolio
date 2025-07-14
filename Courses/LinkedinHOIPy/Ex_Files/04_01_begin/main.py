import requests

response = requests.get(
    "http://api.worldbank.org/v2/countries/USA/indicators/SP.POP.TOTL?per_page=5000&format=json",
)

last_twenty_years = response.json()[1][:20]

for yr in last_twenty_years:
  if not yr["value"]:
    continue 
  display_width = yr["value"] // 10_000_000
  print(f"POPULATION: {display_width * '|#|'} ({yr['value']}) in YEAR: {yr['date']}")