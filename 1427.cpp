#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string Nums = "";
	cin >> Nums;
	int len = Nums.length();
	printf("%d", len);
	int *N = new int[len + 1];
	for (int i = 0; i < len; i++) {
		int num = (int)Nums[i];
		N[i] = num;
		printf("%d", N[i]);
	}

	sort(N, N+len);

	for (int i = 0;i<len; i++)
		printf("%d", N[i]);
	delete[] N;
	return 0;
}