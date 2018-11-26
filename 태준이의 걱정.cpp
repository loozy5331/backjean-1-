#include <iostream>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int forward, back, distance, cur;
		Answer = 0;
		cin >> forward >> back >> distance;
		cur = forward;
		while (cur < distance) {
			cur -= back;
			cur += forward;
			Answer++;
		}
		
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}