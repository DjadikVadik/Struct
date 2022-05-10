//   6.	Описать структуру Device.Написать программу учёта продаж комплектующих.Требования:
//   - поля : тип устройства, наименование, модель, бренд, срок гарантии, цена, дата продажи
//   - функция проверки на срок гарантии
//   - подсчёт количества продаж по имени устройства за указанный срок
//   - вывод всех типов изделий, которые продавались
//   - подсчет суммы всех продаж за указанный период


#include <iostream>
#include <ctime>
#include <string>
#include <vector>

struct Katalog {

private:

	struct Device {

		std::string tipe;   //  - поля : тип устройства, наименование, модель, бренд, срок гарантии, цена, дата продажи
		std::string name;
		std::string model;
		std::string brend;
		time_t guarantee_period;
		double sum;
		time_t date_of_sale;
	};

	std::vector<Device> katalog;

public:

	void set_initial_sale();       // заполнение полей : тип устройства, наименование, модель, бренд, срок гарантии, цена, дата продажи
	void show_katalog();              //   - вывод всех типов изделий, которые продавались
	void search_guarantee_period();   //   - функция проверки на срок гарантии
	void show_sale_for_time();     //   - подсчёт количества продаж по имени устройства за указанный срок
	void show_sum_for_time();    //   - подсчет суммы всех продаж за указанный период
};


int main()
{
	system("chcp 1251 > 0");


}

void Katalog::set_initial_sale()
{
	Device device;

	std::cout << "\nВведите тип проданного устройства: ";
	std::getline(std::cin, device.tipe);

	std::cout << "\nВведите наименование проданного устройства: ";
	std::getline(std::cin, device.name);

	std::cout << "\nВведите модель проданного устройства: ";
	std::getline(std::cin, device.model);

	std::cout << "\nВведите бренд проданного устройства: ";
	std::getline(std::cin, device.brend);

	std::cout << "\nВведите срок гарантии проданного устройства (в днях): ";
	int x;
	std::cin >> x;
	device.guarantee_period = 86400 * x; // в сутках 86400 секунд

	std::cout << "\nВведите стоимоть проданного устройства (в грн): ";
	std::cin >> device.sum;

	device.date_of_sale = time(0);

	this->katalog.push_back(device);
}

void Katalog::show_katalog()
{
	int n = 0;

	for (auto& element : this->katalog)
	{
		char str[26];
		ctime_s(str, 26, &element.date_of_sale);

		std::cout << ++n << ")\t" << element.tipe << "\n\t" << element.name << "\n\t" << element.model << "\n\t"
			<< element.brend << "\n\t" << (int)element.guarantee_period / 86400 << " дней гарантии\n\t"
			<< "стоимость: " << element.sum << " грн\n\t" << "дата продажи: " << str << "\n";
	}
}

void Katalog::search_guarantee_period()
{
	int x;
	std::cout << "Введите номер товара из каталога (от 1 до " << this->katalog.size() << "): ";
	std::cin >> x;

	std::vector<Device>::iterator iter;

	std::advance(iter, x - 1);

	time_t finish = time(0);
	time_t start = finish - iter->guarantee_period;

	if (iter->date_of_sale < start) std::cout << "\nна даный товар гарантия окончена!!!";
	else std::cout << "\nгарантия действительна!!!";
}

void Katalog::show_sale_for_time()
{
	std::string value;
	std::cout << "\nВведите имя устройства : ";
	std::getline(std::cin, value);
	std::cout << "\nУкажите за сколько последних дней выполнить поиск: ";
	int x;
	std::cin >> x;

	time_t finish = time(0);
	time_t start = finish - (x * 86400);

	int n = 0;

	for (auto& element : this->katalog)
	{
		if (element.name == value && element.date_of_sale > start)
		{
			char str[26];
			ctime_s(str, 26, &element.date_of_sale);

			std::cout << ++n << ")\t" << element.tipe << "\n\t" << element.name << "\n\t" << element.model << "\n\t"
				<< element.brend << "\n\t" << (int)element.guarantee_period / 86400 << " дней гарантии\n\t"
				<< "стоимость: " << element.sum << " грн\n\t" << "дата продажи: " << str << "\n";
		}
	}
}

void Katalog::show_sum_for_time()
{
	std::cout << "\nУкажите за сколько последних дней выполнить поиск: ";
	int x;
	std::cin >> x;

	time_t finish = time(0);
	time_t start = finish - (x * 86400);

	double sum = 0;

	for (auto& element : this->katalog)
		if (element.date_of_sale > start) sum += element.sum;

	std::cout << "\nСумма от проданных товаров за последние " << x << " дней : " << sum << " гривен\n";
}