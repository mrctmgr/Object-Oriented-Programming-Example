#ifndef triangle_H
#define tirangle_H
#include <iostream>
#include "shape.h"


using namespace std;

class Triangle: public Shape {
public:
	float area(int);
	int circum(int,int,int);
	bool regular(int,int,int);
	virtual void set_lenofedge(int*) override ;
	virtual int* get_lenofedge(int*) override ;
	virtual int get_numofedge() override ;
	void triangle();
private:
	int k,l,m;//private cek set ve get e cek
	bool reg;//private cek set ve get fonk ekle
	float ar;
	int circ,side;
	//xml kisminda variable oalrak tek seferde yaz
	//qt
};

#endif
