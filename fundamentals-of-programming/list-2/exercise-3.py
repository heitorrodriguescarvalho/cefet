n1 = int(input("Primeiro número: "))
operator = input("Operador: ")
n2 = int(input("Segundo número: "))

result = None

match operator:
  case '+':
    result = n1 + n2
  case '-':
    result = n1 - n2
  case '*':
    result = n1 * n2
  case '/':
    result = n1 / n2
  case _:
    print("Operador inválido!")

if result != None:
  print(f"Resultado: {result}")
  