#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

ostream &m(ostream &o);

int main()
{
    cout << "lets have some fun with flags!" << endl;
    cout.unsetf(ios::dec);
    cout.setf(ios::showpos | ios::showbase | ios::hex);
    cout << 100 << endl;
    cout.setf(ios::oct, ios::oct | ios::hex | ios::dec | ios::showpos);
    cout << 15 << endl;

    cout << "great!" << endl;
    cout.setf(ios::dec, ios::basefield);
    cout << 132;
    cout.setf(ios::scientific, ios::scientific | ios::fixed);
    cout << 132 << endl;//wtf?

    cout << hex << setw(10) << 156 << oct << setw(10) << 156 << dec << setw(10) << 156 << endl;
    
    for (long i = 0; i != 10; i++)
    {
        cout << right << setfill('*') << setw(10) << hex << (long)pow(2, i);
        cout << " " << right << setfill('*') << setw(10) << oct << (long)pow(2, i);
        cout << " " << right << setfill('*') << setw(10) << dec << (long)pow(2, i) << endl;
    }

    cout << m << endl;
    
    return 0;
}

ostream &m(ostream &o)
{
    cout << ":D";
    return o;
}