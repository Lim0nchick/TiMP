#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class base {
public:
	virtual void show() = 0; //pure virt func
	base(int value) {
		this->value = value;
	}
protected:
	int value;
};
class a :public base {
public:
	a(int value) : base(value) {}
	void show() {
		cout << "class A value: " << value << endl;
	}
};
class b :public base {
public:
	b(int value) : base(value) {}
	void show() {
		cout << "class B value: " << value << endl;
	}
};
class c :public base {
public:
	c(int value) : base(value) {}
	void show() {
		cout << "class C value: " << value << endl;
	}
};
class functor {
public:
	virtual base* operator()(int value) = 0;
};
class funcA :public functor {
public:
	base* operator()(int value) {
		return (new a(value));
	}
};
class funcB :public functor {
	base* operator()(int value) {
		return (new b(value));
	}
};
class funcC :public functor {
	base* operator()(int value) {
		return (new c(value));
	}
};

int main()
{
	map<string, functor*> fab;
	vector<base*> vcl;
	funcA aa;
	funcB bb;
	funcC cc;
	fab["A"] = &aa;
	fab["B"] = &bb;
	fab["C"] = &cc;
	int N;
	cin >> N;
	string command;
	cin >> command;

	for (int i = 0; i < N; i++) {
		if (command == "create") {
			string cl;
			int value;
			cin >> cl >> value;
			functor *fc = fab[cl];
			if (fc == NULL) {
				cout << "Only A B C classes availible" << endl;
			}
			else 
			{
				base *bcl = (*fc)(value);
				vcl.push_back(bcl);
			}
		}
		if (command == "showall") {
			for_each(vcl.begin(), vcl.end(), [](base *lb) {lb->show(); });
		}
		cin >> command;
	}

    return 0;
}