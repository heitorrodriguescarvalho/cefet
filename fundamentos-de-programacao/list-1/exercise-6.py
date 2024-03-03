from math import floor

n1 = int(input("Digite o dividendo: "))
n2 = int(input("Digite o divisor: "))

print(f"Dividendo: {n1}")
print(f"Divisor: {n2}")
print(f"Quociente: {floor(n1 / n2)}")
print(f"Resto: {n1 % n2}")