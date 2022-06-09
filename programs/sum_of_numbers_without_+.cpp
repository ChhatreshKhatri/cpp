#include <iostream>
using namespace std;

int add(int x, int y)
{
    int sum =printf("%*c%*c", x, ' ', y, ' ');
	return sum;
}
//

// Driver code
int main()
{
    int a;
    a=45000;
    cout<<printf("space width 10\n%10d",a);cout<<endl;
    cout<<printf("space width 2\n%2d",a);cout<<endl;
	printf("Sum = %d", add(55, 45));
	return 0;
}

// This code is contributed by shubhamsingh10
