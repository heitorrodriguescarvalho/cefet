roleCode = int(input("Código do cargo: "))
currentSalary = int(input("Informe o salário: "))

increase = None

match roleCode:
  case 101:
    increase = 0.15
  case 102:
    increase = 0.25
  case 103:
    increase = 0.3
  case 104:
    increase = 0.45
  case _:
    increase = 0.5

newSalary = currentSalary + currentSalary * increase

print("-" * 30)

print(f"Salário antigo: R${currentSalary:.2f}")
print(f"Salário novo: R${newSalary:.2f}")
print(f"Diferença: R${newSalary - currentSalary:.2f}")