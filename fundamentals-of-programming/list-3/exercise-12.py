pares = 0
impares = 0

lastNum = 0
while (lastNum != -1):
  lastNum = int(input("Digite um número: "))
  if (lastNum >= 0):
    if (lastNum % 2 == 0):
      pares += 1
    else:
      impares += 1

print(f"Total de pares: {pares}")
print(f"Total de ímpares: {impares}")