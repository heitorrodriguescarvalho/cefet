n1 = int(input("Primeiro número: "))
n2 = int(input("Segundo número: "))
n3 = int(input("Terceiro número: "))

print("-" * 30)

if (n1 < n2 and n1 < n3):
  print(f"Menor número: {n1}")
elif (n2 < n1 and n2 < n3):
  print(f"Menor número: {n2}")
elif (n3 < n1 and n3 < n2):
  print(f"Menor número: {n3}")
else:
  print("Informe números distintos!")