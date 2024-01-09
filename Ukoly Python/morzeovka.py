from ntpath import realpath, join, dirname
with open(join(dirname(realpath(__file__)), "morzeovka.txt"), "r", encoding="utf_8") as file: morzeovka = {line[0]: line[2:].strip() for line in file.read().split("\n")}

def text_to_morse(text):
    morse = ''
    for char in text: 
        if char.upper() in morzeovka:
            morse += morzeovka[char.upper()] + ' '
    return morse

text:str = input("Zadej text: ")
morse = text_to_morse(text)
print(f"Text: {text}\nMorse: {morse}")
