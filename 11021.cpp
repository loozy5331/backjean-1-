#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	vector<int> ret;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		ret.push_back(temp1 + temp2);
	}
	for (int i = 0; i < N; ++i)
	{
		cout << "Case #" << i + 1 << ": " << ret[i] << "\n";
	}
	return 0;
}