total = 0

for i in range(33, 100):
  if (i % 3 == 0 or i % 5 == 0):
    total += i

print(f"Total: {total}")