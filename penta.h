#ifndef penta_H
#define penta_H
#include <iostream>
#include "shape.h"


using namespace std;

class Penta : public Shape {
public:
	float area(int);
	float circum(int, int, int, int,int);
	bool regular(int, int, int, int,int);
	virtual void set_lenofedge(int*) override;
	virtual int* get_lenofedge(int*) override;
	virtual int get_numofedge() override;
	void penta();
private:
	int k,l,m,q,p;//private cek set ve get e cek
	bool reg;//private cek set ve get fonk ekle
	float ar;
	int circ, side;
	//xml kisminda variable oalrak tek seferde yaz
	//qt
};

#endif

