#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		vector<int> v;
		int N;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			int num;
			cin >> num;
			v.push_back(num);
		}

		sort(v.begin(), v.end());
		int Answer = 0;
		for (int i = 0; i < v.size(); ++i) {
			if (i % 2 == 0)
				Answer += v[i];
			else
				Answer -= v[i];
		}
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}