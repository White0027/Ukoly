import requests
import re
from os.path import join, realpath, dirname, exists

# if not exists(join(dirname(realpath(__file__)),"Othelo.txt")):
#     resp = requests.get("https://www.gutenberg.org/cache/epub/2267/pg2267.txt")
#     if resp.ok:
#         with open(join(dirname(realpath(__file__)),"othelo.txt"), "x", encoding=resp.apparent_encoding) as f:
#             f.write(resp.text)


# with open(join(dirname(realpath(__file__)),"Othelo.txt"), "r") as f:
    # book = f.readline()

    # slova = re.findall(r"[a-zA-Z]+", book)

    # word_counts = {slovo:slova.count(slovo) for slovo in set(slova)}
        
    # print(sorted(word_counts.items(), key = lambda x: x[1], reverse=True)[:10])
    

with open(join(dirname(realpath(__file__)),"Othelo.txt"), "r", encoding="utf-8") as f:
    book = f.read()

# 1. metoda
    # book = (
    #     book.replace(". . . .", ".")
    #         .replace(". . .", "")
    #     )
    # vety = re.split(r'\b[a-z][a-z]*\b(\b[a-z]*[.!?])(?=\W{1})', book)
    # pocet_vet = len(vety)
    # print(pocet_vet)


#2. metoda
    # vety_bez_tecek = re.split(r'\.{3,}', book)
    # vety = re.split(r'\b[a-z][a-z]*\b(\b[a-z]*[.!?])(?=\W{1})', vety_bez_tecek[0])
    # pocet_vet = len(vety)
    # print(pocet_vet)
    
    
#3. metoda
    # def vety(book):
    #     vety = re.split(r'(?<=[.!?])\s+', book)
    #     pocet = 0
    #     for veta in vety:
    #         slova = veta.split()
    #         has_uppercase = any(slovo[0].isupper() for slovo in slova)
    #         has_lowercase = any(slovo[0].islower() for slovo in slova)
    #         if has_uppercase and has_lowercase:
    #             pocet += 1
    #     return pocet
    # pocet_vet = vety(book)
    # print(pocet_vet)
