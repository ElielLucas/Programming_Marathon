#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int an[10000009];
int Size[10000009];
int finD(int u)
{
    if(u!=an[u])
        return finD(an[u]);
    return u;
}
int mesmoConjunto(int u, int v)
{
    return (finD(u)==finD(v));
}

void unionFind(int u, int v)
{
    int raizU = finD(u);
    int raizV= finD(v);

    if(Size[raizU]>Size[raizV])
    {
        an[raizV]=raizU;
    }else
    {
        an[raizU]=raizV;
        if(Size[raizU]==Size[raizV])
            Size[raizV]++;
    }
}

int kruskal(vector<pair<int,pair<int,int> > > vec)
{
    int saida=0;
    for(int i=0;i<(int)vec.size();i++)
    {
        int u = vec[i].second.first;
        int v= vec[i].second.second;
        if(!mesmoConjunto(u,v))
        {
            saida+=vec[i].first;
            unionFind(u, v);
        }
    }
    return saida;
}

bool crescente(pair<int,pair<int,int> >& a, pair<int,pair<int,int> >&b)
{
    if(a.first<b.first)return true;
    return false;
}
bool desc(pair<int,pair<int,int> >& a, pair<int,pair<int,int> >&b)
{
    if(a.first>b.first)return true;
    return false;
}

int main ()
{
    int N, u, v, w;

    scanf("%d",&N);
    vector<pair<int,pair<int,int> > > one;
    for(int i=1;i<=N;i++)
    {
        an[i]=i;
        Size[i]=1;
        scanf("%d %d %d",&u,&v,&w);
        one.push_back({w,{u, v}});
    }
    sort(one.begin(), one.end(), desc);
    int max = kruskal(one);
    printf("%d\n",max);

    for(int i=1;i<=N;i++)
    {
        an[i]=i;
        Size[i]=1;
    }
    sort(one.begin(), one.end(), crescente);
    int min = kruskal(one);
    printf("%d\n",min);
}

