value = int(input("Valor: "))
rate = int(input("Taxa (em %): "))
time = int(input("Tempo: "))

print(f"Valor final: {value + ( value * (rate/100) * time)}")