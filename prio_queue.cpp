#include <iostream>
#include <queue>
using namespace std;

int main() {
	priority_queue<int> PQueue;
	PQueue.push(7);
	PQueue.push(4);
	PQueue.push(1);
	PQueue.push(2);
	PQueue.push(9);
	PQueue.push(5);
	while (!PQueue.empty()) {
		cout << PQueue.top() << endl;
		PQueue.pop();
	}

	return 0;
}