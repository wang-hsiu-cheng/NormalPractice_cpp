#include<iostream>
#include<stdlib.h>
#include<string>
#include<time.h>

using namespace std;

int main(){
    string tit_all,tit,opt_all,opt,opt1;
    cout<<"name title:";
    getline(cin,tit_all);
    cout<<"name option:";
    getline(cin,opt_all);
    int n,e;
    n=tit_all.length()/4;
    int a[n+1],b[n+1];
    a[0]=n;
    unsigned s;
    s=(unsigned)time(NULL);
    srand(s);
    for(int i=1;i<n+1;i++){
        do{
            a[i]=rand()%n;
            for(int j=0; j<i; j++){
                if(a[i] == a[i-j-1]){
                    e=1;
                    break;
                }
                else{
                    e=0;
                }
            }
        }while(e==1);
    }
    cout<<endl;
    for(int i=1;i<n+1;i++){
        tit=tit_all.substr((i-1)*4,4);
        opt=opt_all.substr((a[i])*4,4);
        opt1=opt_all.substr((n+a[i])*4,4);
        cout<<i<<" "<<tit<<":"<<a[i]+1<<" "<<opt<<" "<<opt1<<endl;
    }
}
