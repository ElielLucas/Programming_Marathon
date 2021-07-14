#include<iostream>
#include<map>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

int ans[5000];
int Size[5000];
pair<int,int> V[5000];
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

bool mesmoConjunto(int u, int v)
{
    return find(u)==find(v);
}

double kruskal()
{
    double saida=0;

    for(int i=0;i<(int)order.size();i++)
    {
        int u = order[i].second.first;
        int v = order[i].second.second;
        int w = order[i].first;
        if(!mesmoConjunto(u,v))
        {
            saida+=w;
            unionFind(u,v);
        }
    }
    return saida;
}

double distancia(int u, int v)
{
    return sqrt(pow((V[u].first - V[v].first),2) + pow((V[u].second - V[v].second),2));
}


int main()
{
    int N, M, O, u, v, w;
    scanf("%d %d %d",&N, &M, &O);

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

    printf("%d\n",saida*2);

}

