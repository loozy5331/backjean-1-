#include <iostream>
using namespace std;

int main()
{
	unsigned long long int N, M;
	cin >> N >> M;
	unsigned long long int mulsum = 1, v;
	for (int i = 0; i < N; i++)
	{
		cin >> v;
		mulsum *= v;
		if (mulsum > M)
			mulsum = mulsum % M;
	}
	cout << (mulsum % M);

	return 0;
}