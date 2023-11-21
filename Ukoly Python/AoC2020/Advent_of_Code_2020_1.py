def precti(filename):
    with open(filename, "r") as file:
        numbers = [int(line.strip()) for line in file]
    return numbers

def dve_cisla(numbers):
    for i, num1 in enumerate(numbers):
        for num2 in numbers[i + 1:]:
            if num1 + num2 == 2020:
                print(f"Soucet {num1} a {num2} je {num1 + num2}")
                print(f"Soucin {num1} a {num2} je {num1 * num2}")
                

def tri_cisla(numbers):
    for i, num1 in enumerate(numbers):
        for j, num2 in enumerate(numbers[i + 1:], start=i + 1):
            for num3 in numbers[j + 1:]:
                if num1 + num2 + num3 == 2020:
                    print(f"Soucet {num1}, {num2}, a {num3} je {num1 + num2 + num3}")
                    print(f"Soucin {num1}, {num2}, a {num3} je {num1 * num2 * num3}")
                    

if __name__ == "__main__":
    number_list = precti("cisla.txt")
    dve_cisla(number_list)
    tri_cisla(number_list)
