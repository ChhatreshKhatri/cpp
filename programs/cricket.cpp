#include<bits/stdc++.h>
using namespace std;
/*
Cricket
Tom is crazy about cricket. He was watching India vs. Australia World cup final match. Australia won the toss and elected to bat first. They finished batting with a score of X. Next, India started to bat and scored Y runs in N number of balls. As Tom is very crazy, he wants to calculate the run rate and check whether there is a probability for India to win or not. Help him calculate the run-rate and check the probability.
INPUT FORMAT & OUTPUT FORMAT:

Input consists of 4 integers. First input corresponds to the total number of balls. Second input corresponds to the total number of runs. Third input corresponds to the number of runs scored. Fourth input corresponds to the number of balls bowled. First output corresponds to the total number of overs. Second output corresponds to the total number of overs finished. Third output corresponds to the current run rate. Fourth output corresponds to total run rate.

Overs: 50 Overs finished: 7.3 Current Run rate: 10.7 Total Run rate: 7.5 Eligible to Win

SAMPLE INPUT:

300

375

78

45

SAMPLE OUTPUT:

50

7.3

10.7

7.5

Eligible to Win

Case 1
Input (stdin)
300
375
78
45
Case 2
Input (stdin)
300
268
23
45
Output (stdout)
50
7.3
3.2
5.4
Not Eligible to Win

Case 3
Input (stdin)
300
456
54
76
Output (stdout)
50
12.4
4.4
9.1
Not Eligible to Win
*/
/*
run rate = number scored/ overs takes
*/
#include<iostream>

#include<iomanip>

using namespace std;

int main()

{

int a,b,x,y;

 std::cin>>a>>b>>x>>y;

 float m = a/6;

 int n = y/6;

 int p = y%6;

 float k = ((float)n + (float)p/10);

 float d = x/k;

 float f = b/m;

 std::cout<<m<<"\n";

 std::cout<<std::fixed<<std::setprecision(1)<<k<<"\n";

 std::cout<<d<<"\n"<<f<<"\n";

 if(d>f)

   std::cout<<"Eligible to Win";

 else

   std::cout<<"Not Eligible to Win";

}

