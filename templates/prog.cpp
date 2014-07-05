#include <iostream>
#include <cmath>
using namespace std;


template <class T, int size> class Insertion
{
	T *t;
	void swap(T &a, T &b) { T x = a; a = b; b = x; }
public:
	Insertion(T *t) { this->t = t; }
	void sort();
};

template <class X> X pow(X x){ return x * x; }
//use char n because there's a limit recursion depth
template <class Y, char n> Y npow(Y y);

int main()
{
	int a[] = { 5, 7, 89, 1, 14, 11 };
	Insertion<int, 6> insertion(a);
	insertion.sort();

	cout << "sorted: ";
	for (int i = 0; i != 6; i++)
		cout << a[i] << ' ';

	char b[] = { 'g', 'a', 'x', 'u', 'b', 'f', 'r', 'm', 'c' };
	Insertion<char, 9> chars(b);
	chars.sort();

        cout << "sorted: ";
        for (int i = 0; i != 9; i++)
                cout << b[i] << ' ';

	cout << "\n\n";

	cout << "pow(9) = " << pow(9) << "\npow('a')=" << pow('a') << "\npow(10.97)=" << pow(10.97) << '\n';
	cout << "npow<int, 4>(2) = " << npow<int, (char)4>(2);
	cout << "\nnpow<char, 3>('h') = " << npow<char, (char)3>('h') << 
	cout << "\nnpow<char, 32>(2) = " << npow<unsigned int, (char)31>(2) << '\n'; 

	return 0;
}

template <class T, int size> void Insertion<T, size>::sort()
{
	for (register int i = 1; i < size; i++)
	{
		register int j = i;
		while (j != 0 && t[j] < t[j - 1])
		{
			swap(t[j], t[j - 1]);
			j--;
		}
	}
}

template <class Y, char n> Y npow(Y y)
{
	if (n > 100)
		return (Y)-1;
	else if (n == 2)
		return y * y;
	else return y * npow<Y, n - 1>(y);
}
