
//     4.	Создать структуру BuyerGuide.В справочник входит база 
//     торговых точек города : название, адрес и телефоны, 
//     специализация(задаётся перечислением), время работы(два поля типа Time).
//     Реализовать функцию добавления / редактирования / удаления торговой 
//     точки в справочник, показа на экран всех торговых точек с сортировкой 
//     по названию / адресу / специализации, поиска по названию / специализации 
//     / времени работы.


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct BuyerGuide {
private:

	struct Buyer {    // структура "торговая точка"

		std::string name;  // имя торговой точки
		std::string address; // адресс
		std::string telefon;  // телефон
		std::string workname; // специализация
		std::string start_time; // время начала работы
		std::string end_time;  // время окончания работы
	};

	std::vector<Buyer> buyers;  // колекция торговых точек

public:

	void set_new_buyer();  // метод добавления новой торговой точки
	void set_del_buyer();  // метод удаления торговой точки
	void set_edit_buyer(); // метод редактирования торговой точки
	void show_name_sort(); // посказ всех торговых точек с сортировкой по имени
	void show_address_sort(); // посказ всех торговых точек с сортировкой по адрессу
	void show_workname_sort(); // посказ всех торговых точек с сортировкой по специализации
	void search_name();   // поиск торговой точки по имени
	void search_workname(); // поиск торговой точки по специализации
	void search_start_time(); // поиск торговой точки по времени начала работы
	void search_end_time();  // поиск торговой точки по времени конца работы
};


int main()
{
	system("chcp 1251 > 0");

	BuyerGuide b;

	b.set_new_buyer();
	b.set_new_buyer();
	b.set_new_buyer();

	b.set_edit_buyer();

	b.show_name_sort();
	b.show_address_sort();
	b.show_workname_sort();

	b.search_name();
	b.search_workname();
	b.search_start_time();
	b.search_end_time();

	b.set_del_buyer();
	b.show_name_sort();
}

void BuyerGuide::set_new_buyer()
{
	Buyer buyer;
	std::string value;

	std::cout << "\nВведите название торговой точки : ";
	std::getline(std::cin, value);
	buyer.name = value;

	std::cout << "\nВведите адресс торговой точки : ";
	std::getline(std::cin, value);
	buyer.address = value;

	std::cout << "\nВведите телефон торговой точки : ";
	std::getline(std::cin, value);
	buyer.telefon = value;

	std::cout << "\nВведите специализацию торговой точки : ";
	std::getline(std::cin, value);
	buyer.workname = value;

	std::cout << "\nВведите время начала работы торговой точки (формат - 08:00): ";
	std::getline(std::cin, value);
	buyer.start_time = value;

	std::cout << "\nВведите время окончания работы торговой точки (формат - 18:00): ";
	std::getline(std::cin, value);
	buyer.end_time = value;

	this->buyers.push_back(buyer);

	system("cls");
}

void BuyerGuide::set_del_buyer()
{
	int x;
	std::cout << "Введите номер торговой точки, которую необходимо удалить (от 1 до " << this->buyers.size() << ") : ";
	std::cin >> x;
	std::cin.ignore(32767, '\n');

	std::vector<Buyer>::iterator i = this->buyers.begin();
	std::advance(i, x - 1);
	this->buyers.erase(i);

	system("cls");
}

void BuyerGuide::set_edit_buyer()
{
	int x;
	std::cout << "Введите номер торговой точки, которую необходимо редактировать (от 1 до " << this->buyers.size() << ") : ";
	std::cin >> x;
	std::cin.ignore(32767, '\n');

	std::string value;

	std::vector<Buyer>::iterator i = this->buyers.begin();
	std::advance(i, x - 1);

	std::cout << "\nВведите название торговой точки : ";
	std::getline(std::cin, value);
	i->name = value;

	std::cout << "\nВведите адресс торговой точки : ";
	std::getline(std::cin, value);
	i->address = value;

	std::cout << "\nВведите телефон торговой точки : ";
	std::getline(std::cin, value);
	i->telefon = value;

	std::cout << "\nВведите специализацию торговой точки : ";
	std::getline(std::cin, value);
	i->workname = value;

	std::cout << "\nВведите время начала работы торговой точки (формат - 08:00): ";
	std::getline(std::cin, value);
	i->start_time = value;

	std::cout << "\nВведите время окончания работы торговой точки (формат - 18:00): ";
	std::getline(std::cin, value);
	i->end_time = value;

	system("cls");
}

void BuyerGuide::show_name_sort()
{
	std::sort(buyers.begin(), buyers.end(), [](const Buyer& b1, const Buyer& b2)
		{
			return b1.name < b2.name;
		});

	std::cout << "\n\n";

	for (int i = 0; i < buyers.size(); i++)
	{
		std::cout << i + 1 << ")  " << buyers[i].name << "\t\t" << buyers[i].address << "\t\t" << buyers[i].telefon
			<< "\t\t" << buyers[i].workname << "\t\t" << buyers[i].start_time << "\t\t" << buyers[i].end_time << "\n";
	}
}

void BuyerGuide::show_address_sort()
{
	std::sort(buyers.begin(), buyers.end(), [](const Buyer& b1, const Buyer& b2)
		{
			return b1.address < b2.address;
		});

	std::cout << "\n\n";

	for (int i = 0; i < buyers.size(); i++)
	{
		std::cout << i + 1 << ")  " << buyers[i].name << "\t\t" << buyers[i].address << "\t\t" << buyers[i].telefon
			<< "\t\t" << buyers[i].workname << "\t\t" << buyers[i].start_time << "\t\t" << buyers[i].end_time << "\n";
	}
}

void BuyerGuide::show_workname_sort()
{
	std::sort(buyers.begin(), buyers.end(), [](const Buyer& b1, const Buyer& b2)
		{
			return b1.workname < b2.workname;
		});

	std::cout << "\n\n";

	for (int i = 0; i < buyers.size(); i++)
	{
		std::cout << i + 1 << ")  " << buyers[i].name << "\t\t" << buyers[i].address << "\t\t" << buyers[i].telefon
			<< "\t\t" << buyers[i].workname << "\t\t" << buyers[i].start_time << "\t\t" << buyers[i].end_time << "\n";
	}
}

void BuyerGuide::search_name()
{
	std::string value;

	std::cout << "\nВведите имя компании для поиска: ";
	std::getline(std::cin, value);

	for (auto iter : this->buyers)
	{
		if (iter.name == value)
			std::cout << iter.name << "\t" << iter.address << "\t" << iter.telefon << "\t"
			<< iter.workname << "\t" << iter.start_time << "\t" << iter.end_time << "\n";
	}
}

void BuyerGuide::search_workname() 
{
	std::string value;

	std::cout << "\nВведите специализацию компании для поиска: ";
	std::getline(std::cin, value);

	for (auto iter : this->buyers)
	{
		if (iter.workname == value)
			std::cout << iter.name << "\t" << iter.address << "\t" << iter.telefon << "\t"
			<< iter.workname << "\t" << iter.start_time << "\t" << iter.end_time << "\n";
	}
}

void BuyerGuide::search_start_time()
{
	std::string value;

	std::cout << "\nВведите время начала работы торговой точки (формат - 08:00) для поиска: ";
	std::getline(std::cin, value);

	for (auto iter : this->buyers)
	{
		if (iter.start_time == value)
			std::cout << iter.name << "\t" << iter.address << "\t" << iter.telefon << "\t"
			<< iter.workname << "\t" << iter.start_time << "\t" << iter.end_time << "\n";
	}
}

void BuyerGuide::search_end_time()
{
	std::string value;

	std::cout << "\nВведите время окончания работы торговой точки (формат - 18:00) для поиска: ";
	std::getline(std::cin, value);

	for (auto iter : this->buyers)
	{
		if (iter.start_time == value)
			std::cout << iter.name << "\t" << iter.address << "\t" << iter.telefon << "\t"
			<< iter.workname << "\t" << iter.start_time << "\t" << iter.end_time << "\n";
	}
}