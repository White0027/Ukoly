import math

class čtverec ():
    def __init__(self, a):
        self.a = a

    def obvod(self):
        return self.a * 4

    def obsah(self):
        return self.a ** 2

class obdelník(čtverec):
    def __init__(self, a, b):
        super().__init__(a)
        self.b = b

    def obvod(self):
        return 2 * (self.a + self.b)

    def obsah(self):
        return self.a * self.b
class krychle(obdelník):
    def __init__(self, a, b, c):
        super().__init__(a, b)
        self.c = c

    def objem(self):
        return self.a * self.b * self.c
    
    def povrch(self):
        return 2 * (self.a * self.b + self.a * self.c + self.b * self.c)
    
class kvádr(krychle):
    def __init__(self, a, b, c):
        super().__init__(a, b, c)
        
    def povrch(self):
        return 2 * (self.a * self.b + self.a * self.c + self.b * self.c)
    
    def objem(self):
        return self.a * self.b * self.c

class kruh ():
    def __init__(self, r):
        self.r = r
        
    def obvod(self):
        return 2 * math.pi * self.r
    
    def obsah(self):
        return math.pi * self.r ** 2

class válec (kruh):
    def __init__(self, r, v):
        super().__init__(r)
        self.v = v
        
    def objem(self):
        return math.pi * self.r ** 2 * self.v
    
    def povrch(self):
        return 2 * math.pi * self.r * (self.r + self.v)

class koule (válec):
    def __init__(self, r, v):
        super().__init__(r, v)
        
    def objem(self):
        return 4/3 * math.pi * self.r ** 3
    
    def povrch(self):
        return 4 * math.pi * self.r ** 2
    
def main():
    ctverec1 = čtverec(5)
    obdelnik1 = obdelník(6, 7)
    krychle1 = krychle(7, 8, 9)
    kvadr1 = kvádr(2, 3, 4)
    kruh1 = kruh(5)
    val1 = válec(6, 7)
    koule1 = koule(8, 9)
    
    print("čtverec:")
    print("Obvod čtverce je:", ctverec1.obvod())
    print("Obsah čtverce je:", ctverec1.obsah())
    
    print("\nObdélník:")
    print("Obvod obdelníku je:", obdelnik1.obvod())
    print("Obsah obdelníku je:", obdelnik1.obsah())
    
    print("\nKrychle:")
    print("Objem krychle je:", krychle1.objem())
    print("Povrch krychle je:", krychle1.povrch())
    
    print("\nKvádr:")
    print("Objem kvádru je:", kvadr1.objem())
    print("Povrch kvádru je:", kvadr1.povrch())
    
    print("\nKruh:")
    print("Obvod kruhu je:", kruh1.obvod())
    print("Obsah kruhu je:", kruh1.obsah())
    
    print("\nVálec:")
    print("Objem válce je:", val1.objem())
    print("Povrch válce je:", val1.povrch())
    
    print("\nKouke:")
    print("Objem koule je:", koule1.objem())
    print("Povrch koule je:", koule1.povrch())
    
if __name__ == "__main__":
    main()