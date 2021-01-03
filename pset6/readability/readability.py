from cs50 import get_string

text = get_string("Text: ")
lenght = len(text)

letters = sentences = 0

sentence_end = [".", "!", "?"]

for i in range(lenght):
    if text[i].isalpha():
        letters += 1
    if text[i] in sentence_end:
        sentences += 1

words = len(text.split())

index = round(0.0588 * (letters/words * 100) - 0.296 * (sentences/words * 100) - 15.8)

if index >= 16:
    print("Grade 16+")
    exit()

elif index < 1:
    print("Before Grade 1")
    exit()

print(f"Grade: {index}")