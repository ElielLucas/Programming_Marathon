#include <iostream>
#include<queue>
#include<vector>
#include<set>
using namespace std;

typedef vector<int> ii;
ii vecAdj[6010];
int pai[6010];
bool visit[6010];
int color[6010];
int colorCount[2] = {0,0};

void dfs(int u, int &cont)
{
    if(!visit[u])
    {
        visit[u]=true;
        bool ok=true;
        if((int)vecAdj[u].size()==0)
        {
            cont++; 
            color[u]=1;
            return;
        }
        for(int i=0;i<(int)vecAdj[u].size();i++)
        {
            int v = vecAdj[u][i];
            dfs(v,cont);
            if(color[v]==1)ok=false;
        }
        if(ok)
        {
            cont++;
            color[u]=1;
        }
    }
}

int main()
{
    int T, N;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for(int i=1;i<=N;i++)
        {
            vecAdj[i].clear();
            visit[i]=false;
            pai[i]=-1;
            color[i]=-1;
        }
        int u, v;
        for(int i=0;i<N-1;i++)
        {
            scanf("%d %d",&u, &v);
            vecAdj[u].push_back(v);
            vecAdj[v].push_back(u);
        }
        int saida=0;
        dfs(1,saida);
        printf("%d\n",saida);
    }
}

