#include<iostream>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int valor[51], W[51],N, pd[51][101];

int knap(int at, int w)
{
    if(at>=N)return 0;
    if(pd[at][w]!=-1)return pd[at][w];

    if(W[at]>w)return pd[at][w] = knap(at+1,w);

    int p1 = valor[at] + knap(at+1, w - W[at]);
    int p2 = knap(at+1, w);

    return pd[at][w] = max(p1,p2);
}

int main()
{
    int T, M, R;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)
            scanf("%d %d", &valor[i], &W[i]);

        scanf("%d %d",&M, &R);
        for(int i=0;i<N;i++)
            for(int j=0;j<=M;j++)
                pd[i][j]=-1;

       int saida = knap(0,M);
       if(saida>=R)printf("Missao completada com sucesso\n");
       else printf("Falha na missao\n");
    }
}

