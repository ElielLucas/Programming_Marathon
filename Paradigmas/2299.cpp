#include<iostream>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int valor[60], W[60],F, pd[60][1010];

int knap(int at, int w)
{
    if(at>=F)return 0;
    if(pd[at][w]!=-1)return pd[at][w];

    if(W[at]>w)return pd[at][w] = knap(at+1,w);

    int p1 = valor[at] + knap(at+1, w - W[at]);
    int p2 = knap(at+1, w);

    return pd[at][w] = max(p1,p2);
}

int main()
{
    int C, cont=1;
    while(scanf("%d %d",&C, &F) && C && F)
    {
        for(int i=0;i<F;i++)
            scanf("%d %d", &W[i],&valor[i]);

        for(int i=0;i<F;i++)
            for(int j=0;j<=C;j++)
                pd[i][j]=-1;

        printf("Teste %d\n", cont++);
        printf("%d\n",knap(0,C));
        printf("\n");
    }
}

