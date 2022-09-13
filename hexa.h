#ifndef hexa_H
#define hexa_H
#include <iostream>
#include "shape.h"


using namespace std;

class Hexa : public Shape {
public:
	float area(int);
	float circum(int, int, int, int, int,int);
	bool regular(int, int, int, int, int,int);
	virtual void set_lenofedge(int*) override;
	virtual int* get_lenofedge(int*) override;
	virtual int get_numofedge() override;
	void hexa();
private:
	int k, l, m, q, p,r;//private cek set ve get e cek
	bool reg;//private cek set ve get fonk ekle
	float ar;
	int circ, side;
	//xml kisminda variable oalrak tek seferde yaz
	//qt

};

#endif

