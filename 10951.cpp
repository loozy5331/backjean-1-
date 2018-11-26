#include <iostream>
#include <vector>
using namespace std;

vector<int> ret;
string s;

int main() 
{
	cin.tie(NULL);
	int a, b;
	while(cin >> a >> b) {
		ret.push_back(a + b);
	}

	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i] << '\n';
	}

	return 0;
}