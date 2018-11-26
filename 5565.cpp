#include <iostream>
using namespace std;

int main()
{
	int Tentotal=0;
	int Ninetotal=0;
	int tmp;
	cin >> Tentotal;
	for (int i = 0; i < 9; i++) {
		cin >> tmp;
		Ninetotal += tmp;
	}
	cout << Tentotal - Ninetotal;
	return 0;
}