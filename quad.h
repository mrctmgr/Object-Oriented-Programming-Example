#ifndef quad_H
#define quad_H
#include <iostream>
#include "shape.h"


using namespace std;

class Quad : public Shape {
public:
	float area(int);
	float circum(int, int, int,int);
	bool regular(int, int, int,int);
	virtual void set_lenofedge(int*) override;
	virtual int* get_lenofedge(int*) override;
	virtual int get_numofedge() override;
	void quad();
private:
	int k, l, m,q;//private cek set ve get e cek
	bool reg;//private cek set ve get fonk ekle
	float ar;
	int circ, side;
	//xml kisminda variable oalrak tek seferde yaz
	//qt

};

#endif

 