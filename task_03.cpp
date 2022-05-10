

//   3.	Реализовать структуру Student, которая содержит поля(char*) 
//   для хранения фамилии, имени, отчества, даты рождения(Date), 
//   домашнего адреса(Address), телефонного номера.Также за каждым 
//   студентом закреплены 3 динамических массива оценок – зачёты, 
//   курсовые работы, экзамены.Реализовать функции заполнения данных 
//   о студенте, распечатки информации о студенте на экран.

#include <iostream>
#include <string>


struct Student {

private:

	std::string surname;
	std::string name;
	std::string patronymic;
	std::string date;
	std::string address;
	std::string telefon;

	int size_ekz = 5;
	int* ekzamen = new int[size_ekz] {};

	int size_zach = 5;
	int* zacheti = new int[size_zach] {};

	int size_kurs = 5;
	int* kursovie = new int[size_kurs] {};

public:

	~Student()   // деструктор класса
	{
		delete[] this->ekzamen;
		delete[] this->zacheti;
		delete[] this->kursovie;
	}

	void set_info_student(); // метод заполнения информации о студенте
	void set_info_ocenki();  // метод заполнения оценок студента

	void get_info_student();  // метод получения информации о студенте
	void get_info_ocenki();   // метод получения информации о оценках студента
};

int main()
{
	system("chcp 1251 > 0");

	Student Vadim;
	Vadim.set_info_student();
	Vadim.set_info_ocenki();
	Vadim.get_info_student();
	Vadim.get_info_ocenki();

}


void Student::set_info_student()
{
	std::string name;
	std::cout << "Введите фамилию студента : ";
	std::getline(std::cin, name);
	this->surname = name;

	std::cout << "Введите имя студента : ";
	std::getline(std::cin, name);
	this->name = name;

	std::cout << "Введите отчество студента : ";
	std::getline(std::cin, name);
	this->patronymic = name;

	std::cout << "Введите дату рождения студента : ";
	std::getline(std::cin, name);
	this->date = name;

	std::cout << "Введите адресс проживания студента : ";
	std::getline(std::cin, name);
	this->address = name;

	std::cout << "Введите телефон студента : ";
	std::getline(std::cin, name);
	this->telefon = name;
}

void Student::set_info_ocenki()
{
	std::cout << "Выбирите наименование работы:\n1 - экзамены\n2 - зачеты\n3 - курсовые\n";
	int n;
	std::cin >> n;

	if (n == 1)
	{
		std::cout << "Введите номер экзамена (1 - 5) : ";
		int x;
		std::cin >> x;

		std::cout << "Введите оценку за экзамен (1 - 12) : ";
		int y;
		std::cin >> y;

		if (x <= 5 && x >= 1 && y <= 12 && y >= 1)
			this->ekzamen[x - 1] = y;

		else std::cout << "Вы ввели некоректные значения!!!\n";
	}

	else if (n == 2)
	{
		std::cout << "Введите номер зачета (1 - 5) : ";
		int x;
		std::cin >> x;

		std::cout << "Введите оценку за зачет (1 - 12) : ";
		int y;
		std::cin >> y;

		if (x <= 5 && x >= 1 && y <= 12 && y >= 1)
			this->zacheti[x - 1] = y;

		else std::cout << "Вы ввели некоректные значения!!!\n";
	}

	else if (n == 3)
	{
		std::cout << "Введите номер курсовой работы (1 - 5) : ";
		int x;
		std::cin >> x;

		std::cout << "Введите оценку за курсовую работу (1 - 12) : ";
		int y;
		std::cin >> y;

		if (x <= 5 && x >= 1 && y <= 12 && y >= 1)
			this->kursovie[x - 1] = y;

		else std::cout << "Вы ввели некоректные значения!!!\n";
	}

	else std::cout << "Вы ввели некоректные значения!!!\n";
}

void Student::get_info_student()
{
	std::cout << "\nФамилия : \t" << this->surname << "\n";
	std::cout << "Имя : \t\t" << this->name << "\n";
	std::cout << "Отчество : \t" << this->patronymic << "\n";
	std::cout << "Дата рождения : " << this->date << "\n";
	std::cout << "Адресс : \t" << this->address << "\n";
	std::cout << "Телефон : \t" << this->telefon << "\n";
}

void Student::get_info_ocenki()
{
	std::cout << "\nпорядковый номер:\t";

	for (int i = 1; i <= 5; i++)
		std::cout << i << "\t";

	std::cout << "\n\nоценки за экзамены:\t";

	for (int i = 0; i < this->size_ekz; i++)
		std::cout << this->ekzamen[i] << "\t";

	std::cout << "\n\nоценки за зачеты:\t";

	for (int i = 0; i < this->size_zach; i++)
		std::cout << this->zacheti[i] << "\t";

	std::cout << "\n\nоценки за курсовые:\t";

	for (int i = 0; i < this->size_kurs; i++)
		std::cout << this->kursovie[i] << "\t";

	std::cout << "\n\n";
}