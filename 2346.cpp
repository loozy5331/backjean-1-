#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
using namespace std;

typedef pair<int, int> P;

int main() {
	int N;
	cin >> N;
	vector<int> ret;
	deque<P> balloon;
	for (int i = 1; i < N+1; ++i) {
		int temp;
		cin >> temp;
		balloon.push_back(make_pair(i,temp));
	}
	
	while (true) {
		P temp = balloon.front();
		balloon.pop_front();
		ret.push_back(temp.first);
		if (balloon.empty()) break;
		bool flag = false;
		if (temp.second >= 0) {
			temp.second--; // 현재 값이 빠지기 때문에
			flag = true;
		}
		for (int i = 0; i < abs(temp.second); ++i) {
			if (flag) {
				P inner_temp = balloon.front();
				balloon.pop_front();
				balloon.push_back(inner_temp);
			}
			else {
				P inner_temp = balloon.back();
				balloon.pop_back();
				balloon.push_front(inner_temp);
			}
		}
	}
	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i];
		if (i < ret.size() - 1) cout << " ";
	}
	
	
}