#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int  val;
string s;

int eval(int &x)
{
    char ch=s[x++];
    if(islower(ch))  return (val>>(ch-'p'))&1;  // 5位上的数表示相应的+，—
    if(ch=='N')  return !eval(x);
    int v1=eval(x), v2=eval(x);
    if(ch=='K') return v1&v2;
    if(ch=='A') return v1|v2;
    if(ch=='C') return !v1|v2;
    if(ch=='E') return v1==v2;
}

int main()
{
    int x;
    while(cin>>s&&s!="0")
    {
       for(val=0;val<32;val++)
            if(!eval(x=0)) break;
       if(val<32)  cout<<"not"<<endl;
       else  cout<<"tautology"<<endl;
    }
    return 0;
}
