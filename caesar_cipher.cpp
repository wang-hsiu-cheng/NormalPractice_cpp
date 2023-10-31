#include <iostream>
#include <cstring>

using namespace std;

int main(){
char words_in[100], words_out[100];
char Arr_abc[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'/*,'\0',',','.',':',';','?','!','+','-','/','*','=','"','@','#','%','&','<','>','(',')','[',']','{','}','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'*/};
int Arr_123[100] = {26};
int N = 0, mode = 0;
int stop = 0;

//��J
cout<<"Caesar cipher"<<endl<<"origine words_in:";
for(int i=0;i<100;i++){
    cin>>words_in[i];
    if(words_in[i]=='.'){
        stop=i;
        break;
    }
}
cout<<endl<<"origine words_in:";
for(int i=0;i<stop;i++){
    cout<<words_in[i];
}

cout<<"\nchoose mode:(0: all possible, 1: input step)";
cin>>mode;

if (mode) {
    cout<<"move step:";
    cin>>N;

    //�C�L�ˬd
    cout<<endl<<"word count:"<<stop<<endl<<"move step:"<<N<<endl;
    cout<<"final words_in:";

    for(int i=0;i<stop;i++) {
        for(int j = 0; j < 26; j++) {        //�ন�Ʀr
            if(words_in[i]==Arr_abc[j]){
                Arr_123[i] = (j + N + 1) % 26;
            }
        }
        for(int j = 0; j < 27; j++) {
            if (Arr_123[i] == j && j < 26) {
                words_out[i] = Arr_abc[j];  //�ন��r
            }
            else if (Arr_123[i] == j && j == 27) {
                words_out[i] = words_in[i];
            }
        }
        cout<<words_out[i];
    }
}
else if (~mode) {
    cout<<"final words_in:";
    for (N = 0; N < 26; N++) {
        for(int i = 0; i < stop; i++) {
            for(int j = 0; j < 26; j++) {        //�ন�Ʀr
                if(words_in[i] == Arr_abc[j]){
                    Arr_123[i] = (j + N + 1) % 26;
                }
            }
            for(int j = 0; j < 27; j++) {
                if (Arr_123[i] == j && j < 26) {
                    words_out[i] = Arr_abc[j];  //�ন��r
                }
                else if (Arr_123[i] == j && j == 27) {
                    words_out[i] = words_in[i];
                }
            }
            cout<<words_out[i];
        }
        cout << endl;
    }
}

return 0;
}
