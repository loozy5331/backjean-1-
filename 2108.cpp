#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> nums;
map<int, int> freq;
vector<int> freqN;

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		nums.push_back(num);
	}


	int average = 0;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += nums[i];
	}
	if (sum > 0) {
		average = (int)(sum / N + 0.5) ;
	}
	else {
		average = (int)(sum*1.0 / N -0.5);
	}
	printf("%d\n", average);


	int mid = N / 2;
	if (N == 1)
		mid = 0;
	sort(nums.begin(), nums.end());
	int MAX = nums[0], MIN = nums[nums.size() - 1];
	printf("%d\n", nums[mid]);

	int mostfreqNum = 0;
	int maxNumeric = 0;
	for (int i = 0; i < N; i++) {
		freq[nums[i]]++;
	}
	for (int i = 0; i < N; i++) {
		if (maxNumeric < freq[nums[i]])
			maxNumeric = freq[nums[i]];
	}
	for (int i = 0; i < N; i++) {
		if (maxNumeric == freq[nums[i]])
			freqN.push_back(nums[i]);
	}
	sort(freqN.begin(), freqN.end());
	unique(freqN.begin(), freqN.end());
	if (freqN.size() >= 2) {
		mostfreqNum = freqN[1];
	}
	else {
		mostfreqNum = freqN[0];
	}
	printf("%d\n", mostfreqNum);
	int range = MAX - MIN;
	if (range < 0)
		range = range*-1;

	printf("%d\n", range);

	return 0;
}