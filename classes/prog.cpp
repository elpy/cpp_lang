#include <iostream>
#include <cstring>
using namespace std;

class it
{
	int size;
	char name[80];
	friend void who(it thing);
	static int heroes;
public:
	it(const char* n, int s){ strcpy(name, n); size = s; heroes++; cout << name << "++\n"; }
	~it(){ heroes--; cout << name << "--\n";}
	void setname(const char* s);
	void setsize(int s);
	void show();
	static it getInstance();
} hero("neo", 78);

class num
{
	int x;
public:
	num(int n) { x = n; }
	void show() { cout << "x = " << x << '\n'; }
};

int main()
{
	std::cout << "Hello!\n";
	who(hero);
	hero.show();


	it batman("Bruce", 32);
	batman.show();

	cout << "**************************\n";

	it x = it::getInstance();
	x.show();

	cout << "**************************\n";
	num y = 789;
	y.show();

	return 0;
}

int it::heroes;

void it::setname(const char* s)
{
	strcpy(name, s);
}

void it::setsize(int s)
{
	size = s;
}

void it::show()
{
	cout << "I am " << name << ". My size's " << size << ". We're legion " << it::heroes << ".\n";
}

void who(it thing)
{
	cout << "Are you " << thing.name << "?\n";
}

it it::getInstance()
{
	it s = it("Klark", 64);
	return s;
}
