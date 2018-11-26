#include <iostream>
#include <algorithm>
using namespace std;

int height[52];
int weight[52];
int grades[52];

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i){
		cin >> height[i] >> weight[i];
	}
	for (int i = 0; i < N; ++i) {
		int grade = 1;
		for (int j = 0; j < N; ++j) {
			if (i == j) continue;
			if ((height[i] < height[j]) && (weight[i] < weight[j])) grade++;
		}
		grades[i] = grade;
	}
	for (int i = 0; i < N; ++i)
	{
		if (i != N - 1) cout << grades[i] << " ";
		else cout << grades[i];
	}
}