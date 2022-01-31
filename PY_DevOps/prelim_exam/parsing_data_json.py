import json
import csv

filename = "covid_cases.json"
filename_csv = "COVID_19_CASES_PARSED_JSON_LICAS.csv"
cols = ["dateRep", "countriesAndTerritories", "cases", "deaths"]

# Data Holders
date = []
country = []
num_cases = []
num_deaths = []

with open(filename, "r") as JSONBuf:
    data = json.load(JSONBuf)

    for every_entry in data["records"]:
        print(every_entry)
        date.append(every_entry[cols[0]])
        country.append(every_entry[cols[1]])
        num_cases.append(every_entry[cols[2]])
        num_deaths.append(every_entry[cols[3]])

with open(filename_csv, "w", newline="") as IOHandler:
    csv_writer = csv.writer(IOHandler)

    # Can't do writerows since I can't modify them as sequence per data.
    csv_writer.writerow(cols) # Write Columns

    assert len(date) == len(country), f"This expects to have the same length~! | {len(date)} | {len(country)}" # Use date as base length along with country as another variable to compare.

    for each_pairs in range(len(num_cases)):
        seq = [
            date[each_pairs],
            country[each_pairs],
            num_cases[each_pairs],
            num_deaths[each_pairs]
        ]

        csv_writer.writerow(seq)

print("Done")
