#include "triangle.h"
#include "shape.h"
#include <iostream>
using namespace std;
			
float Triangle::area(int a) {
	return a * a * 1.71 / 4;
}
int Triangle::circum(int a, int b, int c) {
	return a + b + c;
}
bool Triangle::regular(int a, int b, int c) {
	if (a == b && b == c)
		return true;
	else
		return false;
}
void Triangle :: set_lenofedge(int ar[3]) {
	for (int i = 0; i < 3; i++)
	{	
		cout << "Enter the number " << i + 1 << " edge: ";
		cin >> ar[i];
		cout << endl;
	}
}
int* Triangle :: get_lenofedge(int ar[3]) {
	return ar;
}
int Triangle :: get_numofedge() {
	return 3;
}