// simulate computer random choose number like lottery number, generate 20 numbers that between 1 to 20.
// achieve the function that the 20 numbers don't repeat
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
	int a[20]={},c=0,j=0;
	srand(time(0));
	for(int i=0;i<20;i++){
        a[i]=rand()%20+1;
        do{
            c=0;
            j=0;
            while(j!=i){
                if(a[j]==a[i]){c=1;}
                j++;
            }
            if(c==1){a[i]=rand()%20+1;}
        }while(c==1);
        cout<<a[i]<<" ";
	}
	return 0;
}
