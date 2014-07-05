#include <iostream>
using namespace std;

class Media
{
protected:
	int volume;
public:
	Media(int vol) { volume = vol; }
	void setVolume(int v) { volume = v; }
	virtual void print() { cout << "Media device: Volume=" << volume << ";\n\n"; }
};

class Radio : virtual public Media
{
protected:
	double frequency;
public:
	Radio(double freq, int vol) : Media(vol) { frequency = freq; }
	void setFreq(double f) { frequency = f; }
	void print() { cout << "Radio: Frequency=" << frequency << "; \n\n"; }
};

class TV : virtual public Media
{
protected:
	int channel;
public:
	TV(int c, int vol) : Media(vol) { channel = c; }
	void setChannel(int c) { channel = c; }
	void print() { cout << "TV: Channel=" << channel << "; \n\n"; }
};

class MediaCenter : public Radio, public TV, virtual public Media
{

public:
	MediaCenter(double frequency, int channel, int volume) : Radio(frequency, volume), TV(channel, volume), Media(volume) { }
	void print(){ cout << "MediaCenter. \n\n"; }
};

class A
{
public:
	virtual void print() = 0;
};

class B : public A
{
public:
	void print() { cout << "It's a B\n"; }
};

void print(Media &m);
void print(A &a);

int main()
{
	Media m = 15;
	m.setVolume(22);
	print(m);

	cout << "***********************\n";

	Radio r(101.5, 11);
	r.setFreq(105.7);
	r.setVolume(5);
	print(r);

	cout << "***********************\n";

	TV tv(1, 9);
	tv.print();

	cout << "***********************\n";

	MediaCenter center(88.7, 2, 12);
	center.setFreq(120.8);
	center.setChannel(8);
	center.setVolume(13);
	print(center);

	cout << "***********************\n";
	Radio *p = new Radio(88.7, 11);
	p->print();
	delete p;

	cout << "***********************\n";
	B *b = new B();
	print(*b);
	delete b;

	return 0;
}

void print(Media &m)
{
	m.print();
}

void print(A &a)
{
	a.print();
}
