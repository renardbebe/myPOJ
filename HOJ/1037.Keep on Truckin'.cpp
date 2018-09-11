#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a,b,c;
    while (~scanf("%d%d%d",&a,&b,&c))
    {
        if (a>168&&b>168&&c>168)
            printf ("NO CRASH\n");
        if (a<=168)
            printf ("CRASH %d\n",a);
        else if (b<=168)
            printf ("CRASH %d\n",b);
        else if (c<=168)
            printf ("CRASH %d\n",c);
    }
    return 0;
}
