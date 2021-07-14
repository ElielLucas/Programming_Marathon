#include <iostream>
using namespace std;

int Size[50000];
int an[50000];

int find(int u)
{
    if (an[u] != u)
    {
        return( find(an[u]) );
    }
    return(u);
}

void unionFind(int u, int v)
{
   int raizU = find(u);
   int raizV= find(v);

   if (Size[raizU] > Size[raizV])
   {
       an[raizV] = raizU;
   }
   else
   {
       an[raizU] = raizV;
       if (Size[raizU] == Size[raizV])
       {
            Size[raizV]++;
       }
   }
}

bool mesmoConjunto(int u, int v)
{
    return find(u)==find(v);
}

int main()
{
    char op;
    int N, b, u, v;
    scanf("%d%d",&N,&b);
    for(int i=0;i<N;i++)
    {
         an[i]=i;
         Size[i]=1;
    }

    while(b--)
    {
       cin>>op>>u>>v;
       if(op=='F')       
           unionFind(u, v);
       else if(op=='C')
       {
           if(mesmoConjunto(u,v))printf("S\n");
           else printf("N\n");
       }
    }
}

