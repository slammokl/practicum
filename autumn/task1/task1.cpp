#include "R2Graph.h"
#include <iostream>
#include <vector> 

R2Point find_middle(const R2Point& x1, const R2Point& x2); 
void circumCircle(const std::vector<R2Point>& vertices);

int main() {
    std::vector<R2Point> vertices(3); 
    std::cin >> vertices[0] >> vertices[1] >> vertices[2];
    circumCircle(vertices); 
    return 0; 
}

R2Point find_middle(const R2Point& x1, const R2Point& x2) {
    return R2Point((x1[0] + x2[0]) / 2, (x1[1] + x2[1]) / 2);
}

void circumCircle(const std::vector<R2Point>& vertices) {
	R2Vector AB = R2Vector(vertices[1][0] - vertices[0][0], vertices[1][1] - vertices[0][1]);
	R2Vector BC = R2Vector(vertices[2][0] - vertices[1][0], vertices[2][1] - vertices[1][1]);
	R2Vector CA = R2Vector(vertices[0][0] - vertices[2][0], vertices[0][1] - vertices[2][1])i;

	R2Point midAB = find_middle(vertices[0], vertices[1]);
	R2Point midBC = find_middle(vertices[1], vertices[2]);
	R2Point midCA = find_middle(vertices[2], vertices[0]);
	
}
