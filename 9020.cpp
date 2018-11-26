#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

bool isprime[5500];
vector<int> prime;
const int MAX = 5500;

void eratos() {
	for (int i = 2; i < MAX; ++i)
	{
		if (isprime[i] == true) {
			prime.push_back(i);
			for (int j = i; j < MAX; j += i)
				isprime[j] = false;
		}
	}
}

int main()
{
	vector<pair<int, int>> ret;
	memset(isprime, true, sizeof(isprime));
	isprime[0] = false;
	isprime[1] = false;
	eratos();
	int primelen = prime.size();
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int first, second;
		int num, minDiffer=MAX;
		cin >> num;
		for (int j = 0; j < primelen; ++j) {
			if (prime[j] > num)
				break;
			for (int k = 0; k < primelen; ++k) {
				if (prime[k] > num - prime[j])
					break;
				if (prime[j] + prime[k] == num)
				{
					if (minDiffer > abs(prime[j] - prime[k]))
					{
						minDiffer = abs(prime[j] - prime[k]);
						first = prime[j], second = prime[k];
					}
				}
			}
		}
		ret.push_back(make_pair(first, second));
	}

	for (int i = 0; i < ret.size(); ++i)
	{
		cout << ret[i].first << " " << ret[i].second << endl;
	}

}