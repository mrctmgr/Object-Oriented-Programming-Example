#include <iostream>
#include <fstream>
#include "triangle.h"
#include "quad.h"
#include "penta.h"
#include "hexa.h"
#include "shape.h"
#include "XmlWriter.h"
using namespace std;
bool flag = false;
void trianglexml(string starttag, int side, int k, int l, int m, bool reg,int circum,float area) {
	XmlWriter xml;
	string str;
	if (reg)
		str = "True";
	else
		str = "False";
	xml.writeStartElementTag(starttag);
	xml.writeStartAttribute("Side");
	xml.writeString(to_string(side));
	xml.writeEndAttribute("Side");
	xml.writeStartAttribute("Lengths");
	xml.writeString((to_string(k) + " " + to_string(l) + " " + to_string(m)));
	xml.writeEndAttribute("Lengths");
	xml.writeStartAttribute("Regularity");
	xml.writeString(str);
	xml.writeEndAttribute("Regularity");
	xml.writeStartAttribute("Circumfalence");
	xml.writeString(to_string(circum));
	xml.writeEndAttribute("Circumfalence");
	xml.writeStartAttribute("Area");
	xml.writeString(to_string(area));
	xml.writeEndAttribute("Area");
	xml.writeEndElementTag();
}
void Triangle :: triangle() {
	char c;
	Triangle tri;
	XmlWriter xml;
	main:
		int edge[3];
		tri.set_lenofedge(edge);
		int* ptr;
		ptr = tri.get_lenofedge(edge);
		k = ptr[0];
		l = ptr[1];
		m = ptr[2];
		reg = tri.regular(k, l, m);
		circ = tri.circum(k, l, m);
		if (reg)
			ar = tri.area(k);
		else
			ar = 0;
		side = tri.get_numofedge();
		trianglexml("Triangle", side, k, l, m, reg, circ, ar);
		if (reg)
			cout << "According to entering data this shape is Regular Triangle\n";
		else 
			cout << "According to entering data this shape is Irregular Triangle\n";
	sub_screen:
		cout << "**************************************************************\n";
		cout << "Press 1 to see lenghts of edges\nPress 2 to see how many edges the shape has\nPress 3 to calculate area\n";
		cout << "Press 4 to calculate circumfalence\nPress 5 to show full info about this shape\nPress 0 to exit program\n";
		int chc;
	any:
		cout << "Enter the your choice: ";
		cin >> chc;
		switch (chc) {
		case 1:
			for (int i = 0; i < 3; i++)
				cout << ptr[i] << "\t";
			cout << "\nDo you want to learn another info about this shape(y/n --> return to main menu) to close the program(q): ";
			chc:
			cin >> c;
			if (c == 'y')
				goto sub_screen;
			else if (c == 'n') 
				break;
			else if (c == 'q') {
				xml.writecloseTag("Shape");
				exit(int('q'));
			}
			else
				goto chc;
			break;
		case 2:
			cout << "This shape number of side is: " << side << endl;
			cout << "\nDo you want to learn another info about this shape(y/n --> return to main menu) to close the program(q): ";
			cin >> c;
			if (c == 'y')
				goto sub_screen;
			else if (c == 'n') 
				break;
			else if (c == 'q') {
				xml.writecloseTag("Shape");
				exit(int('q'));
			}
			else
				goto chc;
			break;
		case 5:
			cout << "****************FULL INFO**************\n";
			if (reg)
				cout << "According to entering data this shape is Regular Triangle\n";
			else 
				cout << "According to entering data this shape is Irregular Triangle\n";
			cout << "This shape has " << side << " edges.\n";
			cout << "Lenght of edges are: \n";
			for (int i = 0; i < 3; i++)
				cout << "Number " << i + 1 << " edge is: " << ptr[i] << "\n";
			cout << "This shape'circumfalence is: " << circ << "\n";
			if (reg)
				cout << "This shape's area is: " << ar << endl;
			else 
				cout << "Because of the shape is irregular, area is not calculated.\n";
			cout << "*****************************************\n";
			cout << "\nDo you want to learn another info about this shape(y/n --> return to main menu) to close the program(q): ";
			cin >> c;
			if (c == 'y')
				goto sub_screen;
			else if (c == 'n') 
				break;
			else if (c == 'q') {
				xml.writecloseTag("Shape");
				exit(int('q'));
			}
			else
				goto chc;
			break;
		case 4:
			cout << "This shape's circumfalence is: " << circ << endl;
			cout << "\nDo you want to learn another info about this shape(y/n --> return to main menu) to close the program(q): ";
			cin >> c;
			if (c == 'y')
				goto sub_screen;
			else if (c == 'n') 
				break;
			else if (c == 'q') {
				xml.writecloseTag("Shape");
				exit(int('q'));
			}
			else
				goto chc;
			break;
		case 3:
			if (reg) 
				cout << "This shape's area is: " << ar << endl;
			else 
				cout << "Because of the shape is irregular, area is not calculated.\n";
			cout << "\nDo you want to learn another info about this shape(y/n --> return to main menu) to close the program(q): ";
			cin >> c;
			if (c == 'y')
				goto sub_screen;
			else if (c == 'n') 
				break;
			else if (c == 'q') {
				xml.writecloseTag("Shape");
				exit(int('q'));
			}
			else
				goto chc;
			break;
		case 0:
			xml.writecloseTag("Shape");
			exit(0);
		default:
			cout << "Invalid selection!!!!!!\nPlease enter again...";
			goto any;
		}
}
void quadxml(string starttag, int side, int k, int l, int m, int q, bool reg, int circum, float area) {
	XmlWriter xml;
	string str;
	if (reg)
		str = "True";
	else
		str = "False";
	xml.writeStartElementTag(starttag);
	xml.writeStartAttribute("Side");
	xml.writeString(to_string(side));
	xml.writeEndAttribute("Side");
	xml.writeStartAttribute("Lengths");
	xml.writeString((to_string(k) + " " + to_string(l) + " " + to_string(m) + " " + to_string(m)));
	xml.writeEndAttribute("Lengths");
	xml.writeStartAttribute("Regularity");
	xml.writeString(str);
	xml.writeEndAttribute("Regularity");
	xml.writeStartAttribute("Circumfalence");
	xml.writeString(to_string(circum));
	xml.writeEndAttribute("Circumfalence");
	xml.writeStartAttribute("Area");
	xml.writeString(to_string(area));
	xml.writeEndAttribute("Area");
	xml.writeEndElementTag();
}
void Quad :: quad() {
	char c;
	XmlWriter xml;
	Quad qua;
main:
	int edge[4];
	qua.set_lenofedge(edge);
	int* ptr;
	ptr = qua.get_lenofedge(edge);
	k = ptr[0];
	l = ptr[1];
	m = ptr[2];
	q = ptr[3];
	reg = qua.regular(k, l, m, q);
	circ = qua.circum(k, l, m, q);
	if (reg)
		ar = qua.area(k);
	else
		ar = 0;
	side = qua.get_numofedge();
	quadxml("Quad", side, k, l, m, q, reg, circ, ar);
	if (reg)
		cout << "According to entering data this shape is Square\n";
	else 
		cout << "According to entering data this shape is Irregular Quadliteral\n";
sub_screen:
	cout << "**************************************************************\n";
	cout << "Press 1 to see lenghts of edges\nPress 2 to see how many edges the shape has\nPress 3 to calculate area\n";
	cout << "Press 4 to calculate circumfalence\nPress 5 to show full info about this shape\nPress 0 to exit program\n";
	int chc;
any:
	cout << "Enter the your choice: ";
	cin >> chc;
	switch (chc) {
	case 1:
		for (int i = 0; i < 4; i++) 
			cout << ptr[i] << "\t";
		cout << "\nDo you want to learn another info about this shape(y/n --> return to main menu) to close the program(q): ";
	chc:
		cin >> c;
		if (c == 'y')
			goto sub_screen;
		else if (c == 'n') 
			break;
		else if (c == 'q') {
			xml.writecloseTag("Shape");
			exit(int('q'));
		}
		else
			goto chc;
		break;
	case 2:
		cout << "This shape number of side is: " << side << endl;
		cout << "\nDo you want to learn another info about this shape(y/n --> return to main menu) to close the program(q): ";
		cin >> c;
		if (c == 'y')
			goto sub_screen;
		else if (c == 'n') 
			break;
		else if (c == 'q') {
			xml.writecloseTag("Shape");
			exit(int('q'));
		}
		else
			goto chc;
		break;
	case 5:
		cout << "****************FULL INFO**************\n";
		if (reg)
			cout << "According to entering data this shape is Square\n";
		else 
			cout << "According to entering data this shape is Irregular Quadliteral\n";
		cout << "This shape has " << side << " edges.\n";
		cout << "Lenght of edges are: \n";
		for (int i = 0; i < 4; i++) 
			cout << "Number " << i + 1 << " edge is: " << ptr[i] << "\n";		
		cout << "This shape'circumfalence is: " << circ << "\n";
		if (reg) 
			cout << "This shape's area is: " << ar << endl;
		else 
			cout << "Because of the shape is irregular, area is not calculated.\n";
		cout << "*****************************************\n";
		cout << "\nDo you want to learn another info about this shape(y/n --> return to main menu) to close the program(q): ";
		cin >> c;
		if (c == 'y')
			goto sub_screen;
		else if (c == 'n') 
			break;
		else if (c == 'q') {
			xml.writecloseTag("Shape");
			exit(int('q'));
		}
		else
			goto chc;
		break;
	case 4:
		cout << "This shape's circumfalence is: " << circ << endl;
		cout << "\nDo you want to learn another info about this shape(y/n --> return to main menu) to close the program(q): ";
		cin >> c;
		if (c == 'y')
			goto sub_screen;
		else if (c == 'n') 
			break;
		else if (c == 'q') {
			xml.writecloseTag("Shape");
			exit(int('q'));
		}
		else
			goto chc;
		break;
	case 3:
		if (reg) 
			cout << "This shape's area is: " << ar << endl;
		else 
			cout << "Because of the shape is irregular, area is not calculated.\n";
		cout << "\nDo you want to learn another info about this shape(y/n --> return to main menu) to close the program(q): ";
		cin >> c;
		if (c == 'y')
			goto sub_screen;
		else if (c == 'n')
			break;
		else if (c == 'q') {
			xml.writecloseTag("Shape");
			exit(int('q'));
		}
		else
			goto chc;
		break;
	case 0:
		xml.writecloseTag("Shape");
		exit(0);
	default:
		cout << "Invalid selection!!!!!!\nPlease enter again...";
		goto any;
	}
}
void pentaxml(string starttag, int side, int k, int l, int m, int q,int p, bool reg, int circum, float area){
		XmlWriter xml;
		string str;
		if (reg)
			str = "True";
		else
			str = "False";
		xml.writeStartElementTag(starttag);
		xml.writeStartAttribute("Side");
		xml.writeString(to_string(side));
		xml.writeEndAttribute("Side");
		xml.writeStartAttribute("Lengths");
		xml.writeString((to_string(k) + " " + to_string(l) + " " + to_string(m) + " " + to_string(m) + " "+ to_string(p)));
		xml.writeEndAttribute("Lengths");
		xml.writeStartAttribute("Regularity");
		xml.writeString(str);
		xml.writeEndAttribute("Regularity");
		xml.writeStartAttribute("Circumfalence");
		xml.writeString(to_string(circum));
		xml.writeEndAttribute("Circumfalence");
		xml.writeStartAttribute("Area");
		xml.writeString(to_string(area));
		xml.writeEndAttribute("Area");
		xml.writeEndElementTag();
}
void  Penta :: penta() {
	char c;
	XmlWriter xml;
	Penta pen;
main:
	int edge[5];
	pen.set_lenofedge(edge);
	int* ptr;
	ptr = pen.get_lenofedge(edge);
	k = ptr[0];
	l = ptr[1];
	m = ptr[2];
	q = ptr[3];
	p = ptr[4];
	reg = pen.regular(k, l, m, q, p);
	circ = pen.circum(k, l, m, q, p);
	if (reg)
		ar = pen.area(k);
	else
		ar = 0;
	side = pen.get_numofedge();
	pentaxml("Pentagonal", side, k, l, m, q, p, reg, circ, ar);
	if (reg)
		cout << "According to entering data this shape is Regular Pentagonal\n";
	else 
		cout << "According to entering data this shape is Irregular Pentagonal\n";
sub_screen:
	cout << "**************************************************************\n";
	cout << "Press 1 to see lenghts of edges\nPress 2 to see how many edges the shape has\nPress 3 to calculate area\n";
	cout << "Press 4 to calculate circumfalence\nPress 5 to show full info about this shape\nPress 0 to exit program\n";
	int chc;
any:
	cout << "Enter the your choice: ";
	cin >> chc;
	switch (chc) {
	case 1:
		for (int i = 0; i < 5; i++) 
			cout << ptr[i] << "\t";
		cout << "\nDo you want to learn another info about this shape(y/n --> return to main menu) to close the program(q): ";
	chc:
		cin >> c;
		if (c == 'y')
			goto sub_screen;
		else if (c == 'n') 
			break;
		else if (c == 'q') {
			xml.writecloseTag("Shape");
			exit(int('q'));
		}
		else
			goto chc;
		break;
	case 2:
		cout << "This shape number of side is: " << side << endl;
		cout << "\nDo you want to learn another info about this shape(y/n --> return to main menu) to close the program(q): ";
		cin >> c;
		if (c == 'y')
			goto sub_screen;
		else if (c == 'n')
			break;
		else if (c == 'q') {
			exit(int('q'));
		}
		else
			goto chc;
		break;
	case 5:
		cout << "****************FULL INFO**************\n";
		if (reg)
			cout << "According to entering data this shape is regular Pentagonal\n";
		else 
			cout << "According to entering data this shape is Irregular Pentagonal\n";
		cout << "This shape has " << side << " edges.\n";
		cout << "Lenght of edges are: \n";
		for (int i = 0; i < 5; i++) 
			cout << "Number " << i + 1 << " edge is: " << ptr[i] << "\n";
		cout << "This shape'circumfalence is: " << circ << "\n";
		if (reg) 
			cout << "This shape's area is: " << ar << endl;
		else 
			cout << "Because of the shape is irregular, area is not calculated.\n";
		cout << "*****************************************\n";
		cout << "\nDo you want to learn another info about this shape(y/n --> return to main menu) to close the program(q): ";
		cin >> c;
		if (c == 'y')
			goto sub_screen;
		else if (c == 'n') 
			break;
		else if (c == 'q') {
			xml.writecloseTag("Shape");
			exit(int('q'));
		}
		else
			goto chc;
		break;
	case 4:
		cout << "This shape's circumfalence is: " << circ << endl;
		cout << "\nDo you want to learn another info about this shape(y/n --> return to main menu) to close the program(q): ";
		cin >> c;
		if (c == 'y')
			goto sub_screen;
		else if (c == 'n') 
			break;
		else if (c == 'q') {
			xml.writecloseTag("Shape");
			exit(int('q'));
		}
		else
			goto chc;
		break;
	case 3:
		if (reg) 
			cout << "This shape's area is: " << ar << endl;
		else 
			cout << "Because of the shape is irregular, area is not calculated.\n";
		cout << "\nDo you want to learn another info about this shape(y/n --> return to main menu) to close the program(q): ";
		cin >> c;
		if (c == 'y')
			goto sub_screen;
		else if (c == 'n') 
			break;
		else if (c == 'q') {
			xml.writecloseTag("Shape");
			exit(int('q'));
		}
		else
			goto chc;
		break;
	case 0:
		xml.writecloseTag("Shape");
		exit(0);
	default:
		cout << "Invalid selection!!!!!!\nPlease enter again...";
		goto any;
	}
}
void hexaxml(string starttag, int side, int k, int l, int m, int q, int p, int r, bool reg, int circum, float area) {
	XmlWriter xml;
	string str;
	if (reg)
		str = "True";
	else
		str = "False";
	xml.writeStartElementTag(starttag);
	xml.writeStartAttribute("Side");
	xml.writeString(to_string(side));
	xml.writeEndAttribute("Side");
	xml.writeStartAttribute("Lengths");
	xml.writeString((to_string(k) + " " + to_string(l) + " " + to_string(m) + " " + to_string(q) + " " + to_string(p) + " " + to_string(r)));
	xml.writeEndAttribute("Lengths");
	xml.writeStartAttribute("Regularity");
	xml.writeString(str);
	xml.writeEndAttribute("Regularity");
	xml.writeStartAttribute("Circumfalence");
	xml.writeString(to_string(circum));
	xml.writeEndAttribute("Circumfalence");
	xml.writeStartAttribute("Area");
	xml.writeString(to_string(area));
	xml.writeEndAttribute("Area");
	xml.writeEndElementTag();
}
void Hexa :: hexa(){
	char c;
	XmlWriter xml;
	Hexa hex;
main:
	int edge[6];
	hex.set_lenofedge(edge);
	int* ptr;
	ptr = hex.get_lenofedge(edge);
	k = ptr[0];
	l = ptr[1];
	m = ptr[2];
	q = ptr[3];
	p = ptr[4];
	r = ptr[5];
	reg = hex.regular(k, l, m, q, p,r);
	circ = hex.circum(k, l, m, q, p,r);
	if (reg)
		ar = hex.area(k);
	else
		ar = 0;
	side = hex.get_numofedge();
	pentaxml("Hexagonal", side, k, l, m, q, p, reg, circ, ar);
	if (reg) 
		cout << "According to entering data this shape is Regular Hexagonal\n";
	else 
		cout << "According to entering data this shape is Irregular Hexagonal\n";
sub_screen:
	cout << "**************************************************************\n";
	cout << "Press 1 to see lenghts of edges\nPress 2 to see how many edges the shape has\nPress 3 to calculate area\n";
	cout << "Press 4 to calculate circumfalence\nPress 5 to show full info about this shape\nPress 0 to exit program\n";
	int chc;
any:
	cout << "Enter the your choice: ";
	cin >> chc;
	switch (chc) {
	case 1:
		for (int i = 0; i < 6; i++) 
			cout << ptr[i] << "\t";
		cout << "\nDo you want to learn another info about this shape(y/n --> return to main menu) to close the program(q): ";
	chc:
		cin >> c;
		if (c == 'y')
			goto sub_screen;
		else if (c == 'n') 
			break;
		else if (c == 'q') {
			xml.writecloseTag("Shape");
			exit(int('q'));
		}
		else
			goto chc;
		break;
	case 2:
		cout << "This shape number of side is: " << side << endl;
		cout << "\nDo you want to learn another info about this shape(y/n --> return to main menu) to close the program(q): ";
		cin >> c;
		if (c == 'y')
			goto sub_screen;
		else if (c == 'n') 
			break;
		else if (c == 'q') {
			xml.writecloseTag("Shape");
			exit(int('q'));
		}
		else
			goto chc;
		break;
	case 5:
		cout << "****************FULL INFO**************\n";
		if (reg) 
			cout << "According to entering data this shape is Regular Hexagonal\n";
		else 
			cout << "According to entering data this shape is Irregular Hexagonal\n";
		cout << "This shape has " << side << " edges.\n";
		cout << "Lenght of edges are: \n";
		for (int i = 0; i < 6; i++) 
			cout << "Number " << i + 1 << " edge is: " << ptr[i] << "\n";
		cout << "This shape'circumfalence is: " << circ << "\n";
		if (reg) 
			cout << "This shape's area is: " << ar << endl;
		else 
			cout << "Because of the shape is irregular, area is not calculated.\n";
		cout << "*****************************************\n";
		cout << "\nDo you want to learn another info about this shape(y/n --> return to main menu) to close the program(q): ";
		cin >> c;
		if (c == 'y')
			goto sub_screen;
		else if (c == 'n') 
			break;
		else if (c == 'q') {
			xml.writecloseTag("Shape");
			exit(int('q'));
		}
		else
			goto chc;
		break;
	case 4:
		cout << "This shape's circumfalence is: " << circ<< endl;
		cout << "\nDo you want to learn another info about this shape(y/n --> return to main menu) to close the program(q): ";
		cin >> c;
		if (c == 'y')
			goto sub_screen;
		else if (c == 'n') 
			break;
		else if (c == 'q') {
			xml.writecloseTag("Shape");
			exit(int('q'));
		}
		else
			goto chc;
		break;
	case 3:
		if (reg) 
			cout << "This shape's area is: " << ar << endl;
		else 
			cout << "Because of the shape is irregular, area is not calculated.\n";
		cout << "\nDo you want to learn another info about this shape(y/n --> return to main menu) to close the program(q): ";
		cin >> c;
		if (c == 'y')
			goto sub_screen;
		else if (c == 'n') 
			break;
		else if (c == 'q') {
			xml.writecloseTag("Shape");
			exit(int('q'));
		}
		else
			goto chc;
		break;
	case 0:
		xml.writecloseTag("Shape");
		exit(0);
	default:
		cout << "Invalid selection!!!!!!\nPlease enter again...";
		goto any;
	}
}
void Xmlwriter() {
	XmlWriter xml;
	xml.writeopenTag("Shape");
	//xml.writeStartElementTag(startTag);
	//xml.writeStartAttribute(outAttribute);
	//xml.writeString("");
	//xml.writeEndAttribute("Regularity");
	//xml.writeEndElementTag();
	//xml.writecloseTag();
}
int main() {
	XmlWriter xml;
	xml.writeopenTag("Shape");
	int n;
	Triangle tri;
	Quad qua;
	Penta pen;
	Hexa hex;
any:
	cout << "Welcome to shape program to exit the program press 0...\n";
	cout << "Enter num of edge:";
	cin >> n;
	switch (n)
	{
	case 3:
		tri.triangle();
		goto any;
		break;
	case 4:	
		qua.quad();
		goto any;
		break;
	case 5:
		pen.penta();
		goto any;
		break;
	case 6:
		hex.hexa();
		goto any;
		break;
	case 0:
		xml.writecloseTag("Shape");
		exit(0);
	default: 
		cout << "Invalid Selection !!!!!!!!\nPlease enter again...";
		goto any;
	}
}

