import random

SIZE = 20
numbers = []
odds = []
evens = []

# Seed random generator (optional in Python)
random.seed()

# Generate random numbers
print("Original array:", end=" ")
for _ in range(SIZE):
    num = random.randint(6, 105)  # rand % 100 + 6 → 6 to 105
    numbers.append(num)
    print(num, end=" ")
print()

# Separate odd and even numbers
for num in numbers:
    if num % 2 == 0:
        evens.append(num)
    else:
        odds.append(num)

# Print odd and even values
print("Odd values:", *odds)
print("Even values:", *evens)
