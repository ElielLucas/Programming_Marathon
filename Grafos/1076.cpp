#include <iostream>
#include<vector>
using namespace std;

typedef vector<int> i;
i vecAdj[60];
bool visit[60];
void dfs(int u, int &cont)
{
    for(int i=0;i<(int)vecAdj[u].size();i++)
    {
        int v=vecAdj[u][i];
        if(!visit[v])
        {
            visit[v]=true;
            dfs(v,cont);
            cont+=2;
        }
    }
}

int main()
{
    int T, N, v, a, aux1, aux2;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        scanf("%d%d",&v, &a);
        for(int i=0;i<v;i++)
        {
            visit[i]=false;
            vecAdj[i].clear();
        }
        while(a--)
        {
            scanf("%d%d",&aux1, &aux2);
            vecAdj[aux1].push_back(aux2);
            vecAdj[aux2].push_back(aux1);
        }
        int cont=0;
        visit[N]=true;
        dfs(N,cont);
        for(int i=0;i<N;i++)
        {
            if(!visit[i])dfs(i,cont);
        }
        printf("%d\n",cont);
    }
}

