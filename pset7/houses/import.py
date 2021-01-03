from sys import argv
from cs50 import SQL
import csv

# Check the number of command-line arguments
if len(argv) != 2:
    print("Bad user input")
    exit(1)

# Open students database and create table
open(f"students.db", "w").close()
db = SQL("sqlite:///students.db")

db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEXT, house TEXT, birth NUMERIC)")

chars = open(argv[1], 'r')
reader = csv.DictReader(chars)
headers = reader.fieldnames
headers_count = len(headers)

# Add students data into dictionary
for row in reader:
    student_names = row[headers[0]]
    names_list = student_names.split()
    if len(names_list) != 3:
        names_list.insert(1, None)

    house = row[headers[1]]
    birth = int(row[headers[2]])

    db.execute("INSERT INTO students ('first', middle, 'last', house, birth) VALUES (?, ?, ?, ?, ?)", names_list[0], names_list[1], names_list[2], house, birth)

exit(0)



