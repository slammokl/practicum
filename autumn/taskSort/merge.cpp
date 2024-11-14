#include <iostream> 
#include <vector> 

void mergeSortRecursive(
		std::vector<double>::iterator first, 
		std::vector<double>::iterator last, 
		std::vector<double>* tmpMemory = 0
);

int main() {
	std::vector<double> arr; 
	std::cout << "Введите массив вещественных чисел (для отмены ввода Ctrl+D):" << std::endl; 
        while(std::cin) {
		double tmp;
		std::cin >> tmp;
		arr.push_back(tmp); 
	}
	mergeSortRecursive(arr.begin(), arr.end(), &arr); 	
	return 0;
}

void mergeSortRecursive(
		std::vector<double>::iterator first, 
		std::vector<double>::iterator last, 
		std::vector<double>* tmpMemory
) {
	std::cout << "Merging!" << std::endl;  
}
