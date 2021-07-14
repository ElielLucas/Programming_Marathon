#include<iostream>
#include<map>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

int ans[5000];
int Size[5000];
pair<double,double> V[5000];
vector<pair<double,pair<double,double>>> order;

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

double kruskal()
{
    double saida=0;

    for(int i=0;i<(int)order.size();i++)
    {
        int u = order[i].second.first;
        int v = order[i].second.second;
        double w = order[i].first;
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
    int N;
    double u, v;
    while(scanf("%d",&N)!=EOF)
    {
        order.clear();
        for(int i=1;i<=N;i++)
        {
            ans[i]=i;
            Size[i]=1;
            scanf("%lf %lf", &u, &v);
            V[i]={u,v};
        }


        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(i!=j)
                {
                    double dist=distancia(i,j);
                    order.push_back({dist,{i,j}});
                    order.push_back({dist,{j,i}});
                }
            }
        }
        sort(order.begin(), order.end());

        double saida = kruskal();
        printf("%.2lf\n",saida);
    }
}

