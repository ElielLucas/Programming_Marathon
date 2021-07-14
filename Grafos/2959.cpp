#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

double matrizAdj[410][410];
void floyd_warshall(int N)
{
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                matrizAdj[i][j]=min(matrizAdj[i][j],matrizAdj[i][k] + matrizAdj[k][j]);
            }
        }
    }
}
int main()
{

    int N, M, P, u, v;
    scanf("%d %d %d", &N, &M, &P);

    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            matrizAdj[i][j]=99999999;

    while(M--)
    {
        scanf("%d %d",&u, &v);
        matrizAdj[u][v]=matrizAdj[v][u]=0;
    }

    floyd_warshall(N);
    
    while(P--)
    {
        scanf("%d %d",&u, &v);
        if(matrizAdj[u][v]>0)printf("Deu ruim\n");
        else printf("Lets que lets\n");
    }
}

