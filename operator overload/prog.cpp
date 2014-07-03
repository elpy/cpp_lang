#include <iostream>
using namespace std;

class Family
{
public:
	int people;
	int children;

	Family() { people = 0; children = 0; }
	Family(int a, int b) { people = a; children = b; }
	void print();
	/****/
	Family operator++() { people++; children++; return *this; }
	Family operator++(int i) { people++; children++; return *this; }
	Family operator--() { people--; children--; return *this; }
	Family operator--(int i) { people--; children--; return *this; }
	Family operator+(Family &f);
	Family operator=(Family &f);
	int operator[](int i);
	friend Family operator+(int i, Family &f);
	friend Family operator+(Family &f, int i);
};


int main()
{
	Family f(4, 2);
	f.print();

	cout << "Family inc/dec\n";
	(f++).print();
	(++f).print();
	(--f).print();

	cout << "Family + Family\n";
	Family f2(1, 0);
	(f2 + f).print();

	cout << "int + Family\n";
	(3 + f).print();

	cout << "Family =\n";
	f = f2;
	f.print();

	cout << "Family []\npeople: " << f[0] << " children: " << f[1] << " wrong index: " << f[4] << '\n';


	return 0;
}

void Family::print()
{
	cout << "People = " << people << " children = " << children << '\n';
}

Family Family::operator+(Family &f)
{
	Family t = f;
	t.people += people;
	t.children += children;
	return t;
}

Family Family::operator=(Family &f)
{
	people = f.people;
	children = f.children;
	return *this;
}

int Family::operator[](int i)
{
	if (i == 0)
		return people;
	else if (i == 1)
		return children;
	else return -1;
}

Family operator+(int i, Family &f)
{
	Family t = f;
	t.people += i;
	t.children += i;
	return t;
}

Family operator+(Family &f, int i)
{
	Family t = f;
	t.people += i;
	t.children += i;
	return t;
}
