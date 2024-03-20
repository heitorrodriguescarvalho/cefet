pares = 0

lastNum = 0
while (lastNum != -1):
  lastNum = int(input("Digite um número: "))
  if (lastNum % 2 == 0):
    pares += 1

print(f"Total de nº pares: {pares}")