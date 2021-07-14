#include<iostream>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int valor[120], W[120],N, pd[120][800];

int knap(int at, int w)
{
    if(at>=N)return 0;
    if(pd[at][w]!=-1)return pd[at][w];

    if(W[at]>w)return pd[at][w] = knap(at+1,w);

    int p1 = valor[at] + knap(at, w - W[at]);
    int p2 = knap(at+1, w);

    return pd[at][w] = max(p1,p2);
}

int main()
{
    int M, cont=1;
    while(scanf("%d %d",&N, &M) && N && M)
    {
        for(int i=0;i<N;i++)
            scanf("%d %d", &W[i], &valor[i]);

        for(int i=0;i<N;i++)
            for(int j=0;j<=M;j++)
                pd[i][j]=-1;

        printf("Instancia %d\n%d\n",cont++,knap(0,M));
        printf("\n");
    }
}

