vyska = int(input("Zadejte vysku koruny: "))
kmen_v = int(input("Zadeje vysku kmene: "))
kmen_s = int(input("Zadejte sirku kmene: "))

for i in range(1, vyska + 1):
    print(" " * (vyska - i), end="")
    for j in range(i):
        if j == 0:
            print("*", end="")
        else:
            print("**", end="")
    print()

for i in range(kmen_v):
    print(" " * ((vyska - (kmen_s // 2)) - 1), end="")
    print("#" * kmen_s)
