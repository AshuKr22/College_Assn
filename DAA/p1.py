import random

# Create a list of numbers from 1 to 1000
numbers = list(range(1, 1001))

# Shuffle the list randomly
random.shuffle(numbers)

# Open a text file in write mode
file = open("random_numbers.txt", "w")

# Write each number in the list to the file, separated by a newline
for number in numbers:
    file.write(str(number) + "\n")

# Close the file
file.close()