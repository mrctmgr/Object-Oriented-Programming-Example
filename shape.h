#ifndef shape_H
#define shape_H
#include <iostream>
using namespace std;

class Shape {
public:
	virtual int get_numofedge() = 0;
	virtual void set_lenofedge(int*) = 0;
	virtual int*  get_lenofedge(int*) = 0;
	
protected:
	int n;
};

#endif