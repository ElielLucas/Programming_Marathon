#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

int ans[10000];
int Size[10000];
vector<int> V[10000];
vector<pair<int, pair<int,int>>> order;
bool visitV[10000];

int find(int u)
{
    if(u!=ans[u])return find(ans[u]);
    return u;
}

void unionFind(int u, int v)
{
    int raizU = find(u);
    int raizV = find(v);

    if(Size[raizU]>Size[raizV])
    {
        ans[raizV]=raizU;
    }else
    {
        ans[raizU]=raizV;
        if(Size[raizU]==Size[raizV])
            Size[raizV]++;
    }
}

bool mesmoConjunto(int u, int v)
{
    return find(u)==find(v);
}

int kruskal()
{
    int saida=0;

    for(int i=0;i<(int)order.size();i++)
    {
        int u = order[i].second.first;
        int v = order[i].second.second;
        int w = order[i].first;
        if(!mesmoConjunto(u,v))
        {
            saida+=w;
            V[u].push_back(v);
            V[v].push_back(u);
            unionFind(u,v);
        }
    }
    return saida;
}

void dfs(int u, int &cont)
{
    if(!visitV[u])
    {
        cont++;
        visitV[u]=true;
        for(int i=0;i<(int)V[u].size();i++)
        {
            int v=V[u][i];
            dfs(v,cont);
        }
    }
}


int main()
{
    int N, M, u, v, w;
    while(scanf("%d %d",&N, &M)!=EOF)
    {
        order.clear();
        for(int i=1;i<=N;i++)
        {
            ans[i]=i;
            Size[i]=1;
            visitV[i]=0;
            V[i].clear();
        }
        for(int i=1;i<=M;i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            order.push_back({w,{u,v}});
        }
        sort(order.begin(), order.end());

        int cont=0;
        int saida = kruskal();

        dfs(1,cont);
        if(cont==N)printf("%d\n",saida);
        else printf("impossivel\n");
    }
}

