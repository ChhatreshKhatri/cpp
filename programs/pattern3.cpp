#include<stdio.h>
int main()
{
int i,j,r,count;                                      //declaring integer variables i,j for loops , r for number of rows and count for increment in value
count=1;                                              //initialising count
printf("Enter the number of rows :\n");               //Asking user for input
scanf("%d",&r);                                       //taking number of rows and saving it in variable r
for(i=0;i<r;i++)
  {
    for(j=0;j<=i;j++)
      {
        if(j!=0)
        printf("*%d",count);
        else
        printf("%d",count);
      }
    printf("\n");                                     
    count++;
  }
  count--;
  for(i=r;i>0;i--)
  {
    for(j=i;j>0;j--)
      {
        if(j==1)
        printf("%d",count);
        else
        printf("%d*",count);
      }
    printf("\n");                                     
    count--;
  }
}