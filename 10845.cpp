#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

vector<int> q;
vector<int> ret;

int main()
{
	int N;
	string str;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		if (str == "push") {
			int num;
			cin >> num;
			cin.clear();
			q.push_back(num);
		}
		
			if (str == "front") {
				if (q.size() > 0)
					ret.push_back(q.front());
				else
					ret.push_back(-1);
			}
			if (str == "back") {
				if (q.size() > 0)
					ret.push_back(q.back());
				else
					ret.push_back(-1);
			}
		
		if (str == "empty") {
			ret.push_back(q.empty());
		}
		if (str == "pop") {
			if (q.size() > 0) {
				ret.push_back(q.at(0));
				q.erase(q.begin() + 0);
			}
			else {
				ret.push_back(-1);
			}
		}
		if (str == "size") {
			ret.push_back(q.size());
		}
		
	}

	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << endl;
}