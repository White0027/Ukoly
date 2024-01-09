
from os.path import join, realpath, dirname
from book import Book

class Library():

    def __init__(self, path_to_file):
        self.books = []
        with open(join(dirname(realpath(__file__)), "text.txt"), "r", encoding="utf_8") as f:
            lines = f.readlines()
            for line in lines:
                self.books.append(Book(line.rstrip()))
        self.books.sort()
        
    def add_book(self, book):
        if book not in self.books:
            book.set_id(self.get_unique_id())
            self.books.append(book)
            self.books.sort()
            print("Kniha přidána s ID: ", book.id)
        else:
            print("Kniha nemá unikátní ID")
            
    def get_unique_id(self):
        
        return max(book.id for book in self.books) + 1
    
    def show_available_books(self):
        for book in self.books:
            if book.available == True:
                print(book)
                
    def __repr__(self):
        return "\n".join([str(book) for book in self.books])

    def find_book_and_borrow_it(self, name):
        found_books = []
        for book in self.books:
            if book.available == False:   
                continue
            if name.lower() in book.name.lower():
                found_books.append(book)
        if len(found_books) == 0:
            print("Nenalezena žádná dostupná kniha s tímto jménem.")
            
        elif len(found_books) > 1:
            print("Nalezena více knih, prosím upřesněte hledání:")
            for book in found_books:
                print(book)
            
        elif len(found_books) == 1:
                print("Nalezena tato kniha:")
                print(found_books)
                answer = input("Chcete knihu vypujcit (a/n): ")
                if answer.lower() == "a":
                    print("Kniha vypujcena")
                    found_books[0].available = False
            
        else:
            print("Něco se pokazilo")
