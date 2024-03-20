alunos = int(input("Quantidade de Alunos: "))

print("Caso tenha adicionado todas as notas de determinado aluno, digite -1")
for i in range(1, alunos + 1):
  total = 0
  divisao = 0

  lastNum = 0
  while (lastNum != -1):
    lastNum = int(input(f"Nota do {i}º aluno: "))
    if (lastNum >= 0):
      total += lastNum
      divisao += 1
  
  if (divisao != 0):
    print(f"Média do {1}º aluno: {total / divisao}")