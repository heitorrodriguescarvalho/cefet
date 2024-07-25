itemCode = int(input("Código do item: "))

food = None
price = None

match itemCode:
  case 100:
    food = "Cachorro quente"
    price = 1.2
  case 101:
    food = "Bauru simples"
    price = 1.3
  case 102:
    food = "Bauru com ovo"
    price = 1.5
  case 103:
    food = "Hambúrguer"
    price = 1.2
  case 104:
    food = "Chesseburguer"
    price = 1.3
  case 105:
    food = "Refrigerante"
    price = 1
  case _:
    print('Informe um código válido!')

if food != None and price != None:
  quantity = int(input("Quantidade: "))
  print(f"Valor a pagar: R${price * quantity:.2f}")
