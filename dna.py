import csv
from sys import argv, exit

# checking arguments
if len(argv) != 3:
    print("Usage error: dna.py sequence.txt database.csv")
    exit()

# opening the first one
with open(argv[1], "r") as database:
    reader = csv.reader(database)
    for row in reader:
        dnasequences = row
        dnasequences.pop(0)
        break

# opening the second one
with open(argv[2], "r") as sequence:
    reader1 = csv.reader(sequence)
    for row in reader1:
        dnalist = row

dna = dnalist[0]

sequences = {}

# setting sequence
for item in dnasequences:
    sequences[item] = 1

# getting a loop
for key in sequences:
    l = len(key)
    MAXtemp = 0
    temp = 0
    for i in range(len(dna)):

        while temp > 0:
            temp -= 1
            continue

# doing calculation
        if dna[i: i + l] == key:
            while dna[i - l: i] == dna[i: i + l]:
                temp += 1
                i += l

# fixing 
            if temp > MAXtemp:
                MAXtemp = temp

    sequences[key] += MAXtemp

# last phase
with open(argv[1], newline = '') as peoplefile:
    reader = csv.DictReader(peoplefile)
    for person in reader:
        match = 0

# if it's not matching exit
        for dna in sequences:
            if sequences[dna] == int(person[dna]):
                match += 1
        if match == len(sequences):
            print(person['name'])
            exit()

    print("No match")