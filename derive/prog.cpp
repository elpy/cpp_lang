#include <iostream>
using namespace std;

class Media
{
protected:
	int volume;
public:
	Media(int vol) { volume = vol; }
	void setVolume(int v) { volume = v; }
	void print() { cout << "Media device: Volume=" << volume << ";\n\n"; }
};

class Radio : virtual public Media
{
protected:
	double frequency;
public:
	Radio(double freq, int vol) : Media(vol) { frequency = freq; }
	void setFreq(double f) { frequency = f; }
	void printRadio() { cout << "Radio: Frequency=" << frequency << "; "; print(); }
};

class TV : virtual public Media
{
protected:
	int channel;
public:
	TV(int c, int vol) : Media(vol) { channel = c; }
	void setChannel(int c) { channel = c; }
	void printTV() { cout << "TV: Channel=" << channel << "; "; print(); }
};

class MediaCenter : private Radio, private TV, virtual private Media
{

public:
	MediaCenter(double frequency, int channel, int volume) : Radio(frequency, volume), TV(channel, volume), Media(volume) { }
	Media::setVolume;
	Radio::setFreq;
	TV::setChannel;
	void printCenter(){ cout << "MediaCenter. "; print(); printRadio(); printTV(); }
};

int main()
{
	Media m = 15;
	m.setVolume(22);
	m.print();

	cout << "***********************\n";

	Radio r(101.5, 11);
	r.setFreq(105.7);
	r.setVolume(5);
	r.printRadio();

	cout << "***********************\n";

	TV tv(1, 9);
	tv.printTV();

	cout << "***********************\n";

	MediaCenter center(88.7, 2, 12);
	center.setFreq(120.8);
	center.setChannel(8);
	center.setVolume(13);
	center.printCenter();

	return 0;
}
