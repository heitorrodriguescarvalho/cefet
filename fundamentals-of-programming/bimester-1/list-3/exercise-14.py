n1 = int(input("Primeiro número: "))
n2 = int(input("Segundo número: "))

total = 0
for i in range (n1 + 1, n2):
  total += i

print(f"Total: {total}")