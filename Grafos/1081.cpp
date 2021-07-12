#include <iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;

typedef vector<int> ii;
ii vecAdj[25];
bool visit[25];
bool flag;
void dfs(int u, string saida)
{
    for(int i=0;i<(int)vecAdj[u].size();i++)
    {       
        int v=vecAdj[u][i];
        flag=true;
        if(!visit[v])
        {
            printf("%s%d-%d pathR(G,%d)\n",&saida[0],u,v,v);
            visit[v]=true;
            dfs(v,saida+"  ");
        }else printf("%s%d-%d\n",&saida[0],u,v);
    }
}

int main()
{
    int N, V, E;
    scanf("%d",&N);
    for(int k=1;k<=N;k++)
    {
        scanf("%d %d",&V, &E);
        for(int i=0;i<V;i++)
        {
            vecAdj[i].clear();
            visit[i]=false;
        }
        int aux1, aux2;
        while(E--)
        {
            scanf("%d %d",&aux1, &aux2);
            vecAdj[aux1].push_back(aux2);
            sort(vecAdj[aux1].begin(),vecAdj[aux1].end());
        }
        printf("Caso %d:\n",k);
        string saida;
        for(int i=0;i<V;i++)
        {
            if(!visit[i])
            {
                flag=false;
                saida="  ";
                visit[i]=true;
                dfs(i,saida);
                if(flag)printf("\n");
            }
        }
    }
}

