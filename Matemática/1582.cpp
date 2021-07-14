#include <iostream>
#include<algorithm>
#include <iomanip>
using namespace std;

pair<int,int> maior(int x, int y)
{
    if(x>y)return {x,y};
    else if(x<y)return {y,x};
    return {x,x};
}
int supMdc(int x, int y)
{
    pair<int,int> A = maior(x,y);

    int i, j;
    for(i=A.first, j=A.second; i%j!=0;)
    {
        int aux = i%j;
        i=j;
        j=aux;
    }
    return j;
}
int mdc(int x, int y, int z)
{
    int firstTime = supMdc(x,y);
    return supMdc(firstTime, z);
}

int main ()
{
    int vet[3];
    while(scanf("%d%d%d",&vet[0],&vet[1],&vet[2])!=EOF)
    {
        sort(vet,vet+3);
        if(vet[2]*vet[2]==vet[1]*vet[1] + vet[0]*vet[0])
        {
            if(mdc(vet[2],vet[1],vet[0])==1)printf("tripla pitagorica primitiva\n");
            else printf("tripla pitagorica\n");
        }else printf("tripla\n");
    }
}

