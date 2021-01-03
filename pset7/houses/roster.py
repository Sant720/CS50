from sys import argv
from cs50 import SQL

if len(argv) != 2:
    print("Bad user input")
    exit(1)
    
db = SQL("sqlite:///students.db")

house = argv[1]
query = "SELECT first, middle, last, birth FROM students WHERE house = '{}' ORDER BY last, first".format(house)

roster = db.execute(query)

for student in roster:
    print(student['first'], end=' ')
    if student['middle'] != None:
        print(student['middle'], end=' ')
    print(student['last'], end='')
    print(', born ', end='')
    print(student['birth'])
    
exit(0)