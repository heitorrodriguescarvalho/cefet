price = int(input("Valor da compra: "))
pagamentMethod = input("Forma de pagamento (Vista ou Prazo): ").strip().lower()

if pagamentMethod == "prazo":
  print(f"Valor final da compra: R${price * 1.15:.2f}")
elif pagamentMethod == "vista":
  print(f"Valor final da compra: R${price * 0.9:.2f}")
else:
  print("Forma de pagamento inválida!")