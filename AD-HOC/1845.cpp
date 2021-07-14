#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    char x;
    bool ok=true;
    string saida="";
    while(scanf("%c",&x)!=EOF)
    {
        if((x=='v' || x=='s' || x=='z' || x=='j' || x=='x' || x=='p' || x=='b'))
        {
            if(ok)
            {
                cout<<'f';
                ok=false;
            }
        }
        else if((x=='V' || x=='S' || x=='Z' || x=='J' || x=='X' || x=='P' || x=='B'))
        {
            if(ok)
            {
                cout<<'F';
                ok=false;
            }
        }
        else if((x=='F' || x=='f'))
        {
            if(ok)
            {
                if(x=='F')cout<<'F';
                else cout<<'f';
                ok=false;
            }
        }else
        {
            cout<<x;
            ok=true;
        }

    }
}

