n1 = int(input("Digite o primeiro número: "))
n2 = int(input("Digite o segundo número: "))
n3 = int(input("Digite o terceiro número: "))

m1 = n1
m2 = n2
m3 = n3

print("Ordem Decrescente: ", end="")
for i in range(0, 3):
  if (m1 >= m2 and m1 >= m3):
    print(f"{m1} ", end="")
    m1 = 0
  elif (m2 >= m1 and m2 >= m3):
    print(f"{m2} ", end="")
    m2 = 0
  elif(m3 >= m1 and m3 >= m2):
    print(f"{m3} ", end="")
    m3 = 0

print('\nOrdem Crescente: ', end="")
for i in range(0, 3):
  if (n1 <= n2 and n1 <= n3):
    print(f"{n1} ", end="")
    n1 = float("inf")
  elif (n2 <= n1 and n2 <= n3):
    print(f"{n2} ", end="")
    n2 = float("inf")
  elif(n3 <= n1 and n3 <= n2):
    print(f"{n3} ", end="")
    n3 = float("inf")