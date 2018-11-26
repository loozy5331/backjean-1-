#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int N;
	vector<int> ret;
	cin >> N;
	for (int i = 0; i < N; ++i){
		string temp;
		cin >> temp;
		ret.push_back((temp[0] - '0') + (temp[2] - '0'));
	}
	for (int i = 0; i < N; ++i)
	{
		cout << ret[i] << endl;
	}
	return 0;
}