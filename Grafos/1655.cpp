#include<iostream>
#include<map>
#include<algorithm>
#include<math.h>
#include <queue>
#include<iomanip>
#define inf 999999
using namespace std;

double matrizAdj[110][110];
double floyd_warshall(int N)
{
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                matrizAdj[i][j]=max(matrizAdj[i][j],matrizAdj[i][k] * matrizAdj[k][j]);
            }
        }
    }
    return matrizAdj[1][N];
}
int main()
{
    int N, M, u, v, w;
    while(scanf("%d",&N) && N!=0)
    {
        scanf("%d",&M);

        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                matrizAdj[i][j]=-9999999999;

        for(int i=1;i<=N;i++)
            matrizAdj[i][i]=0;

        while(M--)
        {
            scanf("%d %d %d",&u, &v, &w);
            matrizAdj[u][v]=matrizAdj[v][u]=(w*0.01);
        }

        cout<<fixed<<setprecision(6);
        cout<<floyd_warshall(N)*100<<" percent\n";
    }
}

