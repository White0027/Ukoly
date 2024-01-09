class Book():
    def __init__(self, book):
        self.id, self.name, self.author, self.available = book.split(";")
        self.id = int(self.id)
        self.available = self.available == "Available"

    def set_id(self, id):
        self.id = id
    
    def __lt__(self, other):
        return self.author < other.author
    
    def __eq__(self, other):
        return self.id == other.id
    
    def __repr__(self):
        return f"{self.id};{self.name};{self.author};{'Available' if self.available else 'Borrowed'}"
    
    