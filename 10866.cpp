#include <deque>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	deque<int> dq;
	vector<int> ret;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string str;
		string order = "";
		int Num;
		cin >> str;
		if (str == "push_back") {
			cin >> Num;
			dq.push_back(Num);
		}
		
		if (str == "push_front") {
			cin >> Num;
			dq.push_front(Num);
		}

		if (str == "front") {
			if (dq.empty()) {
				ret.push_back(-1);
				continue;
			}
			else {
				ret.push_back(dq.front());
			}
		}

		if (str == "back") {
			if (dq.empty()) {
				ret.push_back(-1);
				continue;
			}
			else {
				ret.push_back(dq.back());
			}
		}

		if (str == "pop_front") {
			if (dq.empty()) {
				ret.push_back(-1);
				continue;
			}
			else {
				ret.push_back(dq.front());
				dq.pop_front();
			}
		}

		if (str == "pop_back") {
			if (dq.empty()) {
				ret.push_back(-1);
				continue;
			}
			else {
				ret.push_back(dq.back());
				dq.pop_back();
			}
		}

		if (str == "size") {
			ret.push_back(dq.size());
		}

		if (str == "empty") {
			if (dq.empty()) {
				ret.push_back(1);
			}
			else {
				ret.push_back(0);
			}
		}
	}

	for (int i = 0; i < ret.size(); ++i)
	{
		cout << ret[i] << endl;
	}
}