#include "Square.h"
#include "Rectangle.h"

int main()
{
	Square s(5.0);
	std::cout << std::endl;
	std::cout << s.GetName() << " area = " << s.GetArea() << std::endl;
	s.DrawGraphic();
	s.DrawText();

	Rectangle r(5.0, 4.0);
	std::cout << std::endl;
	std::cout << r.GetName() << " area = " << r.GetArea() << std::endl;
	r.DrawGraphic();
	r.DrawText();
	return 0;
}