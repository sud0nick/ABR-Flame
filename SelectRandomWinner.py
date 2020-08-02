import argparse
import numpy as np
import os
import sys
import time

from colorama import init
from termcolor import cprint
from pyfiglet import figlet_format

# Require an input file
parser = argparse.ArgumentParser(description='Select a random name from a FB events guest list.')
parser.add_argument('--file', action='store', dest='file', help='Guest list from FB event.', required=True)
args = parser.parse_args()

# Show banner
os.system('cls')
with open('banner.txt', 'r') as banner:
    lines = banner.readlines()
    print(''.join(lines))

# Parse the file and select valid participants
participants = []
with open(args.file, 'r') as guestList:
    names = [l.rstrip('\n') for l in guestList.readlines()]

    for n in names:
        if n != "Nick Combs":
            participants.append(n)

# Shuffle the list
for i in range(1, np.random.randint(30, 101)):
    if i % 10 == 0:
        print(f"[+] Shuffled participants {i} times...")
        time.sleep(.5)
    np.random.shuffle(participants)

print(f"Shuffled participants a total of {i} times")

print("\n\nAnd the winner is...\n\n")

for i in range(3, 0, -1):
    cprint(figlet_format(str(i), font='banner'), 'yellow')
    time.sleep(1)

cprint(figlet_format("============", font='banner'), 'red')

# Select a name at random
x = np.random.randint(0, len(participants))
winner = participants[x]
names = winner.split(" ")
for name in names:
    cprint(figlet_format(name, font='banner'), 'green')