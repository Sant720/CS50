from sys import argv
import csv

# Prevent bad usage
if len(argv) != 3:
    print("Missing command line argument")
    exit(1)

# Variables to use in memory
people = {}
new_dna = []
STRs = []

# Open database, read into reader, and define metadata
database = open(argv[1], "r")
reader = csv.DictReader(database)
DNA_t = reader.fieldnames
headers = len(DNA_t)

# Add CSV data into people dictionary
for row in reader:
    for i in range(1, headers):
        new_dna.append(int(row[DNA_t[i]]))

    people[row[DNA_t[0]]] = new_dna
    new_dna = []

# Open sequence, read into reader, and define metadata
sequence = open(argv[2], "r")
dna = sequence.read()
dna_lenght = len(dna)

# Iterate over dna and find highest consecutive count of DNA type
for i in range(1, headers):
    marker = dna.find(DNA_t[i])
    t_len = len(DNA_t[i])
    count = 0
    temp_count = 0

    while marker != -1:
        skip = marker + t_len
        while dna[marker:skip] == DNA_t[i]:
            temp_count += 1
            marker += t_len
            skip = marker + t_len

        if temp_count > count:
            count = temp_count

        temp_count = 0
        marker = dna.find(DNA_t[i], marker)

    STRs.append(count)

# Print match
match = "No match"

for name, values in people.items():
    if set(STRs) == set(values):
        match = name
        break

print(match)

# Close and exit
sequence.close()
database.close()
exit(0)
