// Class inheritence.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>

using namespace std;

class Shape
{
public:
	Shape();
};

Shape::Shape()
{
	std::cout << "Vykresli obrazec" << std::endl;
}


class Square : public Shape
{
private:
	int a;
public:
	Square();
	Square(int a);
	
	int obvod();
	int getA();
};

class Rectangle :public Square
{
private:
	int b;
public:
	Rectangle();
	Rectangle(int a, int b);
	
	int getB();
	int print();
};

class Cube :public Square
{
public:
	Cube();
	Cube(int a);
	double volume();
};
	
int main()
{
	
	Square sq1(5);
	
	Rectangle rec1(5, 6);
	
	cout << "Obvod ctverce je: " << sq1.obvod() << endl;
	cout << "Obsah ctverce je: " << sq1.getA() * sq1.getA() << endl;
	
	cout << "Obvod obdelniku je: " << rec1.getA() * 2 + rec1.getB() * 2 << endl;
	cout << "Obsah obdelniku je: " << rec1.getA() * rec1.getB() << endl;
	cout << rec1.print() << endl;
	
	Cube cu1(5);
	
	cout << "Objem krychle je: " << cu1.volume() << endl;
	
	return 0;
}

Square::Square() :Shape()
{
	std::cout << "Vytvraime ctverec" << std::endl;
}

Square::Square(int a)
{
	this->a = a;
	std::cout << "Vytvraime ctverec" << std::endl;
}

Rectangle::Rectangle() :Square()
{
	std::cout << "Vytvraime obdelnik" << std::endl;
}

Rectangle::Rectangle(int a, int b) :Square(a)
{
	this->b = b;
	std::cout << "Vytvraime obdelnik" << std::endl;
}

int Square::getA()
{
	return this->a;
}

int Square :: obvod()
{
	return this->a * 4;
}

int Rectangle::getB()
{
	return this->b;
}

int Rectangle::print()
{
	std::cout << "Obdelnik se stranou "<< getA() << "cm a druhou stranou o delce "<< b << "cm" << std::endl;
	return 0;
}

Cube::Cube()
{
	std::cout << "Vytvraime krychli" << std::endl;
}

Cube::Cube(int a) :Square(a)
{
	std::cout << "Vytvraime krychli" << std::endl;
}

double Cube::volume()
{
	return this->getA() * this->getA() * this->getA();
}
