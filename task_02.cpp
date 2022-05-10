
//  2.	Реализовать структуру Fraction, которая представляет собой 
//  пользовательский тип данных для работы с обыкновенными дробями :
//  Обязательные поля : числитель и знаменатель(целочисленные).
//  Реализовать следующие функции : показ дроби на экран консоли, 
//  показ неправильной дроби как смешанной, показ обыкновенной дроби 
//  как десятичной, возврат значения типа double на основании значений 
//  числителя и знаменателя дроби, сокращение дроби, сравнение дробей,
//  сложение, вычитание, умножение, деление дробей.

#include <iostream>

struct Fraction {

	int chislitel;
	int znamenatel;



	void show_simple_fraction(); // вывод на экран простой дроби
	void show_decimal();  // вывод на экран десятичной дроби
	double get_decimal(); // вернуть в качестве результата десятичную дробь
	void fraction_reduction(); // сокращение простой дроби
	bool operator < (const Fraction& other);  // перегрузка оператора <
	bool operator > (const Fraction& other);  // перегрузка оператора >
	bool operator == (const Fraction& other);   // перегрузка оператора ==
	Fraction operator + (const Fraction& other);  // перегрузка оператора +
	Fraction operator - (const Fraction& other);  // перегрузка оператора -
	Fraction operator * (const Fraction& other);  // перегрузка оператора *
	Fraction operator / (const Fraction& other);  // перегрузка оператора /
};





int main()
{
	system("chcp 1251 > 0");

	Fraction f;
    f.chislitel = 4;
	f.znamenatel = 8;

	Fraction f1;
	f1.chislitel = 2;
	f1.znamenatel = 8;

	Fraction f2 = f / f1;
	f2.show_simple_fraction();
}





void Fraction::show_simple_fraction()  
{
	if (this->chislitel < this->znamenatel) std::cout << "(" << this->chislitel << "/" << this->znamenatel << ")\n";
	else if (this->chislitel == this->znamenatel) std::cout << "1\n";
	else
	{
		int x = this->chislitel / this->znamenatel;
		if (this->chislitel % this->znamenatel == 0)
			std::cout << x << "\n";
		else
		{
			int y = this->chislitel - (x * this->znamenatel);
			std::cout << x << "(" << y << "/" << this->znamenatel << ")\n";
		}	
	}
}

void Fraction::show_decimal() 
{
	std::cout << (double)this->chislitel / this->znamenatel << "\n";
}

double Fraction::get_decimal()
{
	return (double)this->chislitel / this->znamenatel;
}

bool Fraction::operator < (const Fraction& other)
{
	int x = this->chislitel * other.znamenatel;
	int y = other.chislitel * this->znamenatel;

	return (x < y);
}

bool Fraction::operator > (const Fraction& other)
{
	int x = this->chislitel * other.znamenatel;
	int y = other.chislitel * this->znamenatel;

	return (x > y);
}

bool Fraction::operator == (const Fraction& other)
{
	int x = this->chislitel * other.znamenatel;
	int y = other.chislitel * this->znamenatel;

	return (x == y);
}

void Fraction::fraction_reduction()
{
	bool enable;

	do 
	{

		enable = false;

		for (int i = 2; i <= this->znamenatel; i++)
			if (this->chislitel % i == 0 && this->znamenatel % i == 0)
			{
				this->chislitel /= i;
				this->znamenatel /= i;
				enable = true;
			}

	} while (enable);
}

Fraction Fraction::operator + (const Fraction& other)
{
	Fraction f;

	if (this->znamenatel == other.znamenatel)
	{
		f.chislitel = this->chislitel + other.chislitel;
		f.znamenatel = this->znamenatel;
		f.fraction_reduction();
		return f;
	}

	else
	{
		f.chislitel = this->chislitel * other.znamenatel + other.chislitel * this->znamenatel;
		f.znamenatel = this->znamenatel * other.znamenatel;
		f.fraction_reduction();
		return f;
	}
}

Fraction Fraction::operator - (const Fraction& other)
{
	Fraction f;

	if (this->znamenatel == other.znamenatel)
	{
		f.chislitel = this->chislitel - other.chislitel;
		f.znamenatel = this->znamenatel;
		f.fraction_reduction();
		return f;
	}

	else
	{
		f.chislitel = this->chislitel * other.znamenatel - other.chislitel * this->znamenatel;
		f.znamenatel = this->znamenatel * other.znamenatel;
		f.fraction_reduction();
		return f;
	}
}

Fraction Fraction::operator * (const Fraction& other)
{
	Fraction f;

	f.chislitel = this->chislitel * other.chislitel;
	f.znamenatel = this->znamenatel * other.znamenatel;
	f.fraction_reduction();
	return f;
}

Fraction Fraction::operator / (const Fraction& other)
{
	Fraction f;

	f.chislitel = this->chislitel * other.znamenatel;
	f.znamenatel = this->znamenatel * other.chislitel;
	f.fraction_reduction();
	return f;
}