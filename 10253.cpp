#include <iostream>
using namespace std;

int N;
long long a[1001];
long long b[1001];
long long ret[1001];

void find(long long *a, long long *b) {
	for (int i = 0; i < N; ++i) {
		long long c = 1;
		while (true) {
			if (c*a[i] - b[i] == 0) {
				break;
			}
			else if (c*a[i] - b[i] < 0) {
					c++;
			}
			else {
				a[i] = c*a[i] - b[i];
				b[i] = c*b[i];
				//cout << c << endl;
				c = b[i] / a[i];
			}
		}
		ret[i] = c;
	}
}

int main()
{
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> a[i] >> b[i];
	find(a, b);
	for (int i = 0; i < N; ++i)
	{
		cout << ret[i] << "\n";
	}

	return 0;
}
