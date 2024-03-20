cliente = int(input("Código do cliente: "))
while(cliente != 0):
  total = 0

  produto = int(input("Código do produto: "))
  while (produto != -1):
    preco = float(input("Preço do produto: "))
    quantidade = int(input("Quantidade do produto: "))
    total += preco * quantidade

    produto = int(input("Código do produto: "))

  print(f"Total da compra: R${total:.2f}")

  cliente = int(input("Código do cliente: "))