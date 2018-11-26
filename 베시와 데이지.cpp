#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;



int main()
{
	int Bcnt = 0, Dcnt = 0;
	int Bx, By;
	int Dx, Dy;
	int Jx, Jy;
	cin >> Bx >> By;
	cin >> Dx >> Dy;
	cin >> Jx >> Jy;
	int Bdx = abs(Bx - Jx);
	int Bdy = abs(By - Jy);
	int Ddx = abs(Dx - Jx);
	int Ddy = abs(Dy - Jy);
	while (Bdx != 0 && Bdy != 0) {
		Bdx -= 1; 
		Bdy -= 1;
		Bcnt++;
	}
	Bcnt += (Bdx + Bdy);
	Dcnt = (Ddx + Ddy);
	if (Bcnt < Dcnt) {
		cout << "bessie";
	}
	else if (Bcnt > Dcnt) {
		cout << "daisy";
	}
	else {
		cout << "tie";
	}
	
	return 0;
}