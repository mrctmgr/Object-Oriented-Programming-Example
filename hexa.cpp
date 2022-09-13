#include "hexa.h"
float Hexa::area(int a) {
	return a * 3.53 * a / 4;
}
float Hexa::circum(int a, int b, int c, int d, int e,int f) {
	return a + b + c + d + e + f;
}
bool Hexa::regular(int a, int b, int c, int d, int e,int f) {
	if (a == b && b == c && c == d && d == e && e == f)
		return true;
	else
		return false;
}
void Hexa::set_lenofedge(int ar[6]) {
	for (int i = 0; i < 6; i++)
	{
		cout << "Enter the number " << i + 1 << " edge: ";
		cin >> ar[i];
		cout << endl;
	}
}
int* Hexa::get_lenofedge(int ar[6]) {
	return ar;
}
int Hexa::get_numofedge() {
	return 6;
}