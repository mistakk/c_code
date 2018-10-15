#include <vector>
#include <iostream>
using namespace std;
class A {
public:
	int a;
	A() { cout << "A() called!" << endl; };
	~A() { cout << "~A() called!" << endl; };
	virtual void print_t() { cout << "A::print_t() called!" << endl; };
};
class B :public A {
public:
	int a;
	B() { cout << "B() called!" << endl; };
	~B() { cout << "~B() called!" << endl; };
	virtual void print_t() { cout << "B::print_t() called!" << endl; };
};

int main() {
	int a = 1;
	int &b = a;
	int c = 1;
	
	return 0;
}