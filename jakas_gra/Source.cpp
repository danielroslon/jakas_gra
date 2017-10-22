#include <SFML/Graphics.hpp>
#include <iostream>

#include "gra.h"

using namespace sf;


int main()
{
	int x, y;
	bool fullscreen;

	std::cout.width(15);
	std::cout.setf(std::ios::left);
	std::cout << "Resolution:" << std::endl;
	std::cout << "X: "; 
	std::cin >> x;
	std::cout << "Y: ";
	std::cin >> y;
	std::cout << std::endl;
	
	std::cout.width(15);
	std::cout<< "Fullscreen:" << std::endl;
	std::cout << "(0/1): ";
	std::cin>>fullscreen;
	
	gra g(x,y,fullscreen);
	g.start();





	return 0;
}
