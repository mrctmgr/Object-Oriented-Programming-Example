#include "quad.h"

float Quad::area(int a) {
	return a * a ;
}
float Quad::circum(int a, int b, int c,int d) {
	return a + b + c + d;
}
bool Quad::regular(int a, int b, int c,int d) {
	if (a == b && b == c && c == d)
		return true;
	else
		return false;
}
void Quad::set_lenofedge(int ar[4]) {
	for (int i = 0; i < 4; i++)
	{
		cout << "Enter the number " << i + 1 << " edge: ";
		cin >> ar[i];
		cout << endl;
	}
}
int* Quad::get_lenofedge(int ar[4]) {
	return ar;
}
int Quad::get_numofedge() {
	return 4;
}