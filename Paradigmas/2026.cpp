#include<iostream>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int valor[310], W[310],pac, pd[310][1010];

int knap(int id, int w)
{
    if(id>=pac)return 0;
    if(pd[id][w]!=-1)return pd[id][w];

    if(W[id]>w)return pd[id][w] = knap(id+1,w);

    int p1 = valor[id] + knap(id+1, w - W[id]);
    int p2 = knap(id+1, w);


    return pd[id][w] = max(p1,p2);
}

int main()
{
    int N, pesoMax;
    scanf("%d",&N);
    for(int k=1;k<=N;k++)
    {
        scanf("%d %d",&pac, &pesoMax);
        for(int i=0;i<pac;i++)
            scanf("%d %d",&valor[i], &W[i]);

        for(int i=0;i<pac;i++)
            for(int j=0;j<=pesoMax;j++)
                pd[i][j]=-1;

        printf("Galho %d:\n", k);
        printf("Numero total de enfeites: %d\n",knap(0,pesoMax));
        printf("\n");
    }
}


