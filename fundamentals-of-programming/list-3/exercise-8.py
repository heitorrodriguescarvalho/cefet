total = 0
divisao = 0

for i in range(1, 11):
  num = int(input(f"{i}º número: "))
  if (num >= 18):
    total += num
    divisao += 1

print(f"Média: {total / divisao}")