// cppm-5-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

class Figure {
protected:
	int sides = 0;
public:
	virtual bool check() {
		return 1;
	}
	virtual void print() {
		cout << "Фигура:\n";
		cout << (check() ? "Правильная" : "Неправильная") << "\n";
		cout << "Колличество сторон: " << sides << "\n\n";
	}
};
 
class Triangle : public Figure {
protected:
	int a, b, c;
	int A, B, C;
public:
	Triangle() {
		sides = 3;
		a = 0;
		b = 0;
		c = 0;
		A = 0;
		B = 0;
		C = 0;
	}
	Triangle(int a, int b, int c, int A, int B, int C) {
		sides = 3;
		this->A = A;
		this->a = a;
		this->B = B;
		this->b = b;
		this->C = C;
		this->c = c;
	}
	bool check() override {
		return (A + B + C) == 180;
	}

	void print() override{
		cout << typing() + "\n";
		cout << (check() ? "Правильная" : "Неправильная") << "\n";
		cout << "Колличество сторон: " << sides << "\n";
		cout << print_type()<<"\n";
	}
	virtual std::string print_type() {
		if (a == b && c == b && A == 60 && B == 60 && C == 60) {
			return "Стороны: a = " + to_string(a) + " b = " + to_string(b) + " c = " + to_string(c) + "\nУглы : A = " + to_string(A) + " B = " + to_string(B) + " C = " + to_string(C) + "\n";
		}
		else if (a == c && A == C) {
			return "Стороны: a = " + to_string(a) + " b = " + to_string(b) + " c = " + to_string(c) + "\nУглы : A = " + to_string(A) + " B = " + to_string(B) + " C = " + to_string(C) + "\n";
		}
		else if (C == 90) {
			return "Стороны: a = " + to_string(a) + " b = " + to_string(b) + " c = " + to_string(c) + "\nУглы : A = " + to_string(A) + " B = " + to_string(B) + " C = " + to_string(C) + "\n";
		}
		else {
			return "Стороны: a = " + to_string(a) + " b = " + to_string(b) + " c = " + to_string(c) + "\nУглы : A = " + to_string(A) + " B = " + to_string(B) + " C = " + to_string(C) + "\n";
		}
	}
private:
	string typing() {
		if (a == b && c == b && A == 60 && B == 60 && C == 60) {
			return "Равносторонний треугольник:";
		}
		else if (a == c && A == C) {
			return "Равнобедренный треугольник";
		}
		else if (C == 90) {
			return "Прямоугольный треугольник:";
		}
		else {
			return "Треугольник:";
		}
	}
};

class Quadrilateral :public Triangle {
	int d, D;
public:
	Quadrilateral() :Triangle(){
		sides = 4;
		d = 0;
		D = 0;
	}
	Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) : Triangle(a,b,c,A,B,C){
		sides = 4;
		this->D = D;
		this->d = d;
	}
	bool check() override {
		return (A + B + C + D) == 360;
	}

	void print() override{
		cout << typing() + "\n";
		cout << (check() ? "Правильная" : "Неправильная") << "\n";
		cout << "Колличество сторон: " << sides << "\n";
		cout << print_type() << "\n";
	}
	std::string print_type() override {
		
		if (a == c && c == b && c == d && A == 90 && B == 90 && C == 90 && D == 90) {
			return "Стороны: a = " + to_string(a) + " b = " + to_string(b) + " c = " + to_string(c) + " d = " + to_string(d) + "\nУглы : A = " + to_string(A) + " B = " + to_string(B) + " C = " + to_string(C) + " D = " + to_string(D) + "\n";
		}
		else if (a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90) {
			return "Стороны: a = " + to_string(a) + " b = " + to_string(b) + " c = " + to_string(c) + " d = " + to_string(d) + "\nУглы : A = " + to_string(A) + " B = " + to_string(B) + " C = " + to_string(C) + " D = " + to_string(D) + "\n";
		}
		else if (b == c && a == b && c == d && A == C && B == D) {
			return "Стороны: a = " + to_string(a) + " b = " + to_string(b) + " c = " + to_string(c) + " d = " + to_string(d) + "\nУглы : A = " + to_string(A) + " B = " + to_string(B) + " C = " + to_string(C) + " D = " + to_string(D) + "\n";
		}
		else if (a == c && b == d && A == C && B == D) {
			return "Стороны: a = " + to_string(a) + " b = " + to_string(b) + " c = " + to_string(c) + " d = " + to_string(d) + "\nУглы : A = " + to_string(A) + " B = " + to_string(B) + " C = " + to_string(C) + " D = " + to_string(D) + "\n";
		}
		else {
			return "Стороны: a = " + to_string(a) + " b = " + to_string(b) + " c = " + to_string(c) + " d = " + to_string(d) + "\nУглы : A = " + to_string(A) + " B = " + to_string(B) + " C = " + to_string(C) + " D = " + to_string(D) + "\n";
		}
	}
private:
	string typing() {
		if (a == c && c == b && c == d && A == 90 && B == 90 && C == 90 && D == 90) {
			return "Квадрат:";
		}
		else if (a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90) {
			return "Прямоугольник:";
		}
		else if (b == c && a == b && c == d && A == C && B == D) {
			return "Ромб:";
		}
		else if (a == c && b == d && A == C && B == D) {
			return "Параллелограмм:";
		}
		else {
			return "Четырёхугольник:";
		}

	}

};

int main()
{
	setlocale(LC_ALL, "Russian");

	Figure fig;

	Triangle a(10, 20, 30, 50, 60, 70);
	Triangle c(10, 20, 30, 50, 60, 90);
	Triangle e(10, 20, 10, 50, 60, 50);
	Triangle g(30, 30, 30, 60, 60, 60);

	Quadrilateral b(10, 20, 30, 40, 50, 60, 70, 80);
	Quadrilateral d(10, 20, 10, 20, 90, 90, 90, 90);
	Quadrilateral f(20, 20, 20, 20, 90, 90, 90, 90);
	Quadrilateral h(20, 30, 20, 30, 30, 40, 30, 40);
	Quadrilateral j(30, 30, 30, 30, 30, 40, 30, 40);
	fig.print();
	a.print();
	c.print();
	e.print();
	g.print();
	b.print();
	d.print();
	f.print();
	h.print();
	j.print();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
