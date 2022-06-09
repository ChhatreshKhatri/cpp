/*
Online shopping
Arun wants to buy a shirt. As he is very lazy, he decided to buy the shirt online. He chooses a shirt in Flipkart and is surprised to see the same shirt in Amazon and Snapdeal as well. So he decided to buy the shirt from the website which offers it at the least price. The price of the shirt, discount % and the shipping charges of all three websites have been given as input. Help him in calculating the price of the shirt in each website and decide which website has the lowest price.
INPUT & OUTPUT FORMAT:

Input consist of 9 integers. First three input corresponds to Flipkart details such as the amount of the shirt, discount offered and shipping charges. Next three input corresponds to Snapdeal details such as the amount of shirt, discount offered and shipping charge. Last three input corresponds to amazon details such as the amount of shirt, discount offered and shipping charge.

SAMPLE INPUT:

1000

50

50

900

50

70

800

10

200

SAMPLE OUTPUT:

In Flipkart: Rs.550

In Snapdeal: Rs.520

In Amazon: Rs.920

He will prefer Snapdeal

Case 1
Input (stdin)
1000
60
80
900
50
30
1000
10
200

Output (stdout)
In Flipkart Rs.480
In Snapdeal Rs.480
In Amazon Rs.1100
He will prefer Flipkart

Case 2
Input (stdin)
1000
60
80
900
50
30
1000
10
200

Output (stdout)
In Flipkart Rs.480
In Snapdeal Rs.480
In Amazon Rs.1100
He will prefer Flipkart

Case 3
Input (stdin)
1000
60
80
900
50
30
1000
90
89

Output (stdout)
In Flipkart Rs.480
In Snapdeal Rs.480
In Amazon Rs.189
He will prefer Amazon

*/
#include<iostream>
using namespace std;
int main()
{
  int f1,f2,f3,s1,s2,s3,a1,a2,a3;
  //1000 50 50 900 50 70 800 10 200
  cin>>f1>>f2>>f3>>s1>>s2>>s3>>a1>>a2>>a3;
  int fp=f1-f1*f2/100+f3;
  int sp=s1-s1*s2/100+s3;
  int ap=a1-a1*a2/100+a3;
  cout<<"In Flipkart Rs."<<fp<<endl;
  cout<<"In Snapdeal Rs."<<sp<<endl;
  cout<<"In Amazon Rs."<<ap<<endl;
  
  (fp<=sp)?
    (fp<ap?cout<<"He will prefer Flipkart":cout<<"He will prefer Amazon")
    :(sp<ap?cout<<"He will prefer Snapdeal":cout<<"He will prefer Amazon");
}