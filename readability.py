import cs50

#setting everything for the beginning
letter_count = 0
word_count = 1
sentence_count = 0

#user input
text = cs50.get_string("The Text: ")
text_length = len(text)

#counting letters
for i in range(text_length):
    if(text[i].isalpha()):
        letter_count += 1

#counting words
    if(text[i].isspace()):
        word_count += 1

#counting sentences
    if(text[i] == "." or text[i] == "?" or text[i] == "!"):
        sentence_count += 1

#calculating
index = (0.0588 * letter_count / word_count * 100) - (0.296 * sentence_count / word_count * 100) - 15.8

finality = round(index)

if finality < 1:
    print("Before grade 1 ")

elif finality > 16:
    print("Grade 16+ ")

else:
    print(f"Grade {finality}")
