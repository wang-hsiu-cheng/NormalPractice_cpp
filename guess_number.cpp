/*
generate a 3-digits number as the answer. 
The user will input the number he guess.
If input is larger than the answer, then print out the hint "太大".
If input is smaller than the answer, then print out the hint "太小".
Output the answer and howmany times that the user guess until the input and the answer are equal.
*/
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
	int a,n,c=0;
	srand(time(0));
	a=rand()%900+100;
	do
	{
	  cin>>n;
	  c++;
	  if(a<n)
	     cout<< "太大";
	  if(a>n)
	     cout<< "太小";
	}while(a!=n);
    cout<<"ya! You got it! "<<"times:"<<c;
	return 0;
}
