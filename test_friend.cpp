#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class FriendScore {
public:
	int highestScor(vector<string> friends)
	{
		int ans = 0;
		int n = friends[0].length();

		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				if (friends[i][j] == 'Y') cnt++;
				else {
					for (int k = 0; k < n; k++) {
						if (friends[j][k] == 'Y' && friends[k][i] == 'Y') // 관련있는 사람이 하나라도 있는지 확인.
						{
							cnt++;
							break;
						}
					}
				}
			}
			ans = max(ans, cnt);
		}
		return ans;
	
	}
};

int main()
{
	vector<string> fl = { "NYNNN", "YNYNN", "NYNYN", "NNYNY", "NNNYN"};
	FriendScore f;
	cout << f.highestScor(fl) << endl;
	return 0;
}