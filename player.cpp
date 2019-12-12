#include<iostream>
#include<string.h>

using namespace std;

class Player {
	string name;
public:
	Player(string p) : name(p) {}

	void set_name(string p) {
		name = p;
	}
	string pname() {
		return name;
	}

};