#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> input;
vector<int> output;

int main() 
{
	for (int i = 0; i < 9; ++i)
	{
		int temp;
		cin >> temp;
		input.push_back(temp);
	}
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		sum += input[i];
	}

	bool flag = false;
	for (int i1 = 0; i1 < 9; ++i1) {
		for (int i2 = i1 + 1; i2 < 9; ++i2) {
			if ((sum - (input[i1] + input[i2])) == 100)
			{
				//cout << input[i1] << ", " << input[i2] <<  endl;
				for (int i = 0; i < 9; ++i) {
					if (i != i1 && i != i2)
					{
						output.push_back(input[i]);
					}
				}
				flag = true;
				break;
			}
		}
		if (flag)
		{
			break;
		}
	}

	sort(output.begin(), output.end());
	for (int i = 0; i < 7; ++i)
	{
		cout << output[i] << endl;
	}


	return 0;
}