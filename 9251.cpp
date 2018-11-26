#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string first, second;
int ret = 0;
//int cache[1001][1001];
int lcs(string s1, string s2) {
	if (s1.length() == 0 || s2.length() == 0) return 0;
	int ret = 0;
	for (int i = 0; i < s1.length(); ++i) {
		for (int j = 0; j < s2.length(); ++j) {
			if (s1[i] == s2[j]) {
				ret += lcs(s1.substr(i+1), s2.substr(j+1)) + 1;
			}
		}
	}
	return ret;
}

int main()
{
	//memset(cache, -1, sizeof(cache));
	cin >> first >> second;
	cout << lcs(first, second);
	return 0;
}