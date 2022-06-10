/*
Mango tree - I
Dora is so much interested in gardening and hence she plants more trees in her garden. She plants trees in a rectangular fashion with the order of rows and columns and numbers the trees in a row-wise order. She planted the mango tree only in the 1st row, 1st column and last column. So, given the tree number, your task is to find out whether the given tree is a mango tree or not? Now, write a program to check whether the given number denotes a mango tree or not.
INPUT FORMAT:

Input consists of 3 integers.

The first input denotes the number of rows.

The second input denotes the number of columns.

The third input denotes the tree number.

OUTPUT FORMAT:

If the given number is a mango tree, print "Yes". Otherwise, print "No"

Refer the sample output for formatting.

SAMPLE INPUT:

5

5

11

SAMPLE OUTPUT:

Yes

Case 1
Case 2
Case 3
Input (stdin)
5
5
11

Output (stdout)
Yes

Input (stdin)
2
5
8

Output (stdout)
No

Input (stdin)
2
5
3

Output (stdout)
Yes

*/
#include<iostream>

using namespace std;

int main()

{

 int row,col,num,col2,col3,col4,col5,row2;

 std::cin>>row>>col>>num;

 col2=col*2;

 col3=col*3;

 col4=col*4;

 col5=col*5;

 row2=row*2;

 if(num>1 && num<=col)

   std::cout<<"Yes";

 else if(num==col || num==col2 || num==col3 || num==col4 || num==col5)

   std::cout<<"Yes";

 else if(num==(col+1) || num==(col2+1) || num==(col3+1) || num==(col4+1) || num==(col5+1))

   std::cout<<"Yes";

 else

   std::cout<<"No";

}

