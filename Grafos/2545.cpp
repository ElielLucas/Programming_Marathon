#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<int> ii;
typedef pair<int, int> p;
ii vecAdj[1010];
int visit[1010];
int altura[1010];

void dfs(int u,int &maiorAltura, bool &possivel)
{
    if(!possivel)return;
    if(visit[u]==-1) //se branco
    {
        visit[u]=0; // set cinza       

        int maxHChild=-2;
        for(int i=0;i<(int)vecAdj[u].size();i++)
        {
            int v = vecAdj[u][i];
            dfs(v,maiorAltura, possivel);
            if(altura[v]>maxHChild)maxHChild=altura[v];
        }
        if((int)vecAdj[u].empty())altura[u]=1;
        else
            altura[u]=maxHChild+1;

        if(altura[u]>maiorAltura)maiorAltura=altura[u];

        visit[u]=1; //set preto
    }else if(visit[u]==0)
        possivel=false;
}


int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {       
        for(int i=1;i<=N;i++)
        {
            visit[i]=-1;
            vecAdj[i].clear();
            altura[i]=0;
        }

        int u,v;
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&u);
            while(u--)
            {
                scanf("%d",&v);
                vecAdj[v].push_back(i);
            }
        }
        bool possivel=true;

        int resul=-1;
        for(int i=1;i<=N;i++)
        {
            if(visit[i]==-1)
            {
                dfs(i,resul,possivel);
            }
        }

        if(possivel)printf("%d\n",resul);
        else printf("%d\n",-1);
    }
}

