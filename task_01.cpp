
//  1.	Создать структуру Rectangle, описывающую прямоугольник.
//  Написать функцию для определения попадания произвольной точки 
//  в данный прямоугольник.Точка также должна описываться отдельной 
//  структурой Point.Прямоугольник состоит из двух точек.

#include <iostream>

struct Rectangle;

struct Point {

	friend Rectangle;

	int x;
	int y;
};

struct Rectangle {

	Point left_up;
	Point right_down;

	Rectangle(Point point1, Point point2)
	{
		this->left_up.x = point1.x;
		this->left_up.y = point1.y;

		this->right_down.x = point2.x;
		this->right_down.y = point2.y;	
     }

	bool In_Rectangle(Point& point);
};

bool Rectangle :: In_Rectangle(Point& point)
{
	return (this->left_up.x <= point.x && this->right_down.x >= point.x) && (this->left_up.y >= point.y && this->right_down.y <= point.y);
}

int main()
{
	system("chcp 1251 > 0");

	Point point;
	point.x = 3; point.y = 3;

	Point left_up;
	left_up.x = 2; left_up.y = 6;

	Point right_down;
	right_down.x = 6; right_down.y = 2;

	Rectangle rectangle(left_up, right_down);

	if (rectangle.In_Rectangle(point)) std::cout << "точка принадлежит прямоугольнику!!!\n\n";
	else std::cout << "точка не принадлежит прямоугольнику!!!\n\n";

}