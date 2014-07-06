#include <iostream>
#include <cstring>

using namespace std;

class BaseException
{
protected:
	char message[80];
	int code;
public:
	BaseException(int c, const char *m){ code = c; strcpy(message, m); }
	virtual void print() = 0;
};

class NetworkException : public BaseException
{
public:
	NetworkException(int c, const char *m) : BaseException(c, m) {  }
	void print() { cout << "message: " << message << "; code:  " << code << ";"; }
};

class ConnectionException : public NetworkException
{
public:
	ConnectionException(int c, const char *m) : NetworkException(c, m) {  }
	void print() { cout << "message: " << message << "; code: " << code << ";";  }
};

void doWork();

int main()
{
	try
	{
		doWork();
		cout << "Done.\n";
	}
	catch(ConnectionException co)
	{
		cout << "A connection exception has occurred: ";
		co.print();
		cout << "\n";
	}
	catch(NetworkException ne)
	{
		cout << "A network exception has occurred: ";
		ne.print();
		cout << "\n";
	}
	catch(...)
	{
		cout << "Something went wrong. Chip&Dale are coming!\n";
	}


	return 0;
}

void doWork()
{
	int w;
	cout << "Type magic integer: ";
	cin >> w;

	if (w % 3 == 2)
		throw NetworkException(w, "Can't resolve host address.");
	else if (w % 3 == 1)
		throw ConnectionException(w, "Invalid login or password.");
	else if (w % 9 == 0)
		throw -1;
}
