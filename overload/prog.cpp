#include <iostream>
using namespace std;

class X
{
	int a;
	int *p;
public:
	X();
	X(int a) { this->a = a; *p = 0; }
	X(X &x);
	~X();
	void set(int a) { this->a = a; *p = a; }
	void set(int a, int b) { this->a = a; *p = b; }
	friend void print(X &x);
};

void print(X &x);

int main()
{
	X x;
	print(x);

	x.set(12);
	print(x);

	x.set(1, 2);
	print(x);

	cout << "*******************\n";

	//X y; //i don't know yet how to override =
	//y = x;
	//print(y);

	X z = x;
	print(z);

	cout << "*******************\n";
	X *arr = new X[3];
	delete [] arr;
	cout << "*******************\n";

	return 0;
}

void print(X &x)
{
	cout << "a = " << x.a << " *p = " << *x.p << " p = " << x.p <<  '\n';
}

X::X()
{
	cout << "default ctor" << '\n';
	a = 0;
	p = new int;
	*p = 0;
}

X::~X()
{
	delete p;
	cout << "destructor" << '\n';
}

X::X( X &x)
{
	a = x.a;
	p = new int;
	*p = *x.p;
	cout << "copy ctor" << '\n';
}
