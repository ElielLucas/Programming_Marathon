#include<iostream>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int valor[1000010], W[1000010],pd[10010][10010],M;
int knap(int id, int w)
{
    if (w == 0) return 1;
    if (w < 0) return 0;
    if (id == M) return 0;

    if(pd[id][w]!=-1)return pd[id][w];

    if(W[id]>w)return pd[id][w] = knap(id+1,w);

    int p1 = knap(id+1, w - W[id]);
    int p2 = knap(id+1, w);

    return pd[id][w] = max(p1,p2);
}

int main()
{
    int valorMax;

    scanf("%d %d",&valorMax,&M);

    for(int i=0;i<M;i++)
    {
        scanf("%d",&valor[i]);
        W[i]=valor[i];
    }

    for(int i=0;i<M;i++)
        for(int j=0;j<=valorMax;j++)
            pd[i][j]=-1;

    int saida = knap(0,valorMax);

    if(saida)printf("S\n");
    else printf("N\n");
}


