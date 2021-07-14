#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

bool primo(int num)
{
    int raiz =sqrt(num);
    for(int  i=2; i<= raiz; i++)
    {
        if(num%i==0)return false;
    }
    return true;
}
int main ()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int x;
        cin>>x;
        if(primo(x))printf("Prime\n");
        else printf("Not Prime\n");
    }
}

