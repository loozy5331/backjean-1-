#include <iostream>
#include <vector>
using namespace std;

vector<int> ret;

int main()
{
	cin.tie(NULL);
	int a = 0, b=0;
	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		ret.push_back(a + b);
	}
	
	for (int i = 0; i < ret.size(); ++i){
		cout << ret[i] << endl;
	}
	return 0;
}