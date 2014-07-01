#include <iostream>
using namespace std;

class A
{
	int x;
public:
	A(int x) { this->x = x; }
	int get() { return x; }
};

class B
{
	int x;
public:
	void set(int x) { this->x = x; }
	int get() { return x; }
};

void printA(A *a);
void printB(B &b); 

int main()
{
	A a[] = { 5, 99, 87, 3, 15 };
	B b[5];

	for (int i = 0; i != 5; i++)
	{
		b[i].set(a[i].get() * 9);
	}

	for (int i = 0; i != 5; i++)
	{
		printA(&a[i]);
		printB(b[i]);
	}

	cout << "************************************\n";
	cout << "a[0] address: " << &a[0] << '\n';

	A* a0 = new A(667);
	cout << "a0 address: " << a0 << "and value: " << a0->get() << '\n';
	delete a0;

	cout << "************************************\n";
	B *b0 = new B[2];
	b0->set(11);
	printB(*b0);
	b0++;
	b0->set(13);
	printB(*b0);
	delete [] --b0;

	return 0;
}





void printA(A *a)
{
	cout << "A = " << a->get() << '\n';
}

void printB(B &b)
{
	cout << "B = " << b.get() << '\n';
}
