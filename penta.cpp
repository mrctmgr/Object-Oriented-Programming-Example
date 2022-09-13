#include "penta.h"
float Penta::area(int a) {
	return a * a / 2;
}
float Penta::circum(int a, int b, int c, int d,int e) {
	return a + b + c + d+ e;
}
bool Penta::regular(int a, int b, int c, int d,int e) {
	if (a == b && b == c && c == d && d == e)
		return true;
	else
		return false;
}
void Penta::set_lenofedge(int ar[5]) {
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter the number " << i + 1 << " edge: ";
		cin >> ar[i];
		cout << endl;
	}
}
int* Penta::get_lenofedge(int ar[5]) {
	return ar;
}
int Penta::get_numofedge() {
	return 5;
}