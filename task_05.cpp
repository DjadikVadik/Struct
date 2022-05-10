
//  5.	Описать структуру Check :
//  Предусмотреть функцию добавления информации о товаре
//  (наименование, количество, цена за единицу товара, скидка) 
//  в чек, функцию распечатки чека на экране консоли.


#include <iostream>
#include <string>
#include <vector>


struct Check {

private:

	struct Product {
		std::string name;
		double number;
		double price;
		double discount;
		double sum;
	};

	std::vector<Product> check;

public:

	void set_check()
	{
		Product product;

		std::cout << "\nВведите название товара: ";
		std::getline(std::cin, product.name);

		std::cout << "Введите количество товара: ";
		std::cin >> product.number;

		std::cout << "Введите стоимость товара: ";
		std::cin >> product.price;

		std::cout << "Введите скидку на еденицу товара в процентах: ";
		std::cin >> product.discount;

		product.sum = product.number * (product.price - product.price * (product.discount / 100));

		this->check.push_back(product);
	}

	void show_check()
	{
		for (auto& element : this->check)
			std::cout << "\n\n" << element.name << "\t" << element.number << " шт\t\t\t" << element.price << " грн\t"
			<< element.discount << "%\t" << element.sum << " грн\n";
	}
};


int main()
{
	system("chcp 1251 > 0");

	Check check;
	int n;

	do
	{
		std::cout << "\n\nДля ввода нового продукта введите 1\n"
			<< "Для вывода чека на экран введите 2\n"
			<< "Для выхода введите 3\n";

		std::cin >> n;
		std::cin.ignore(32767, '\n');

		if (n == 1) check.set_check();
		else if (n == 2) check.show_check();
		else if (n == 3) break;

	} while (true);

}
