#include <iostream>
#include "R2Graph.h"

R2Point find_mid(const R2Point& x1, const R2Point& x2);

int main() {
	R2Point a; 
	R2Point b;
	R2Point c;

	std::cin >> a;
	std::cin >> b;
	std::cin >> c;;
	return 0;
}

R2Point find_mid(const R2Point& x1, const R2Point& x2) {
	return R2Point((x1[0] + x2[0]) / 2, (x1[1] + x2[1]) / 2);
}

