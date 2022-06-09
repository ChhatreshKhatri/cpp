
//https://www.geeksforgeeks.org/output-of-c-program-set-18-3/
//https://www.quora.com/What-is-the-meaning-of-instance-of-a-class-and-instantiating-terms-in-Java
// CPP Program to print 1 to 100 without loops and recursion
#include <iostream>
using namespace std;

class A {
public:
	static int a;
	A() { cout << a++ << endl; }
};

int A::a = 1;

// Driver Code
int main()
{
	int N = 100;
	A obj[N];
	return 0;
}
