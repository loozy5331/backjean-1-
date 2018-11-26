#include <iostream>
#include <vector>
using namespace std;

vector<int> ret;

int main()
{
	int N, tempA, tempB;
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> tempA >> tempB;
		ret.push_back(tempA + tempB);
	}
	for (int i = 0; i < N; ++i)
		cout << ret[i] << endl;
	
	return 0;
}