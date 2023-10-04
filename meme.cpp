#include <vector>
#include <iostream>

int main(){
	std::vector<int>  vecInt;
	vecInt.push_back(5);
	vecInt.push_back(2);
	vecInt.push_back(6);
	vecInt.push_back(7);
	vecInt.push_back(8);
	std::vector<int>::iterator it;

	vecInt.insert(it, 5, 1);

	for(int i : vecInt)
		std::cout << i << "\n";
} 
