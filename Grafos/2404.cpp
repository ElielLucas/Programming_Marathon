#include<iostream>
#include<map>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

int ans[510];
int Size[510];
pair<int,int> V[510];
vector<pair<int,pair<int,int>>> order;

int find(int u)
{
    if(u!=ans[u])return ans[u]=find(ans[u]);
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

double kruskal()
{
    double saida=0;

    for(int i=0;i<(int)order.size();i++)
    {
        int u = order[i].second.first;
        int v = order[i].second.second;
        int w = order[i].first;
        if(find(u)!=find(v))
        {
            saida+=w;
            unionFind(u,v);
        }
    }
    return saida;
}

int main()
{
    int N, M, u, v, w;
    scanf("%d %d",&N, &M);

    for(int i=1;i<=N;i++)
    {
        ans[i]=i;
        Size[i]=1;
    }
    while(M--)
    {
        scanf("%d %d %d",&u, &v, &w);
        order.push_back({w,{u,v}});
        order.push_back({w,{v,u}});
    }

    sort(order.begin(), order.end());

    int saida = kruskal();

    printf("%d\n",saida);
}

