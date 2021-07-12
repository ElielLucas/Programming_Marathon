#include <iostream>
#include<vector>
#include<set>
#include <algorithm>
using namespace std;

typedef pair<int, int> kk;
typedef vector< kk > ii;
int Size[50000];
int an[50000];
ii vecAdj[50000];

int find(int u)
{
    if (an[u] != u)
    {
        return( find(an[u]) );
    }
    return(u);
}

void unionFind(int u, int v)
{
   int raizU = find(u);
   int raizV= find(v);

   if (Size[raizU] > Size[raizV])
   {
       an[raizV] = raizU;
   }
   else
   {
       an[raizU] = raizV;
       if (Size[raizU] == Size[raizV])
       {
            Size[raizV]++;
       }
   }
}

bool mesmoConjunto(int u, int v)
{
    return find(u)==find(v);
}

int Kruskal(vector< pair<int, pair<int, int> > > E)
{
    int resul = 0;
    for(int i = 0; i<(int)E.size(); i++)
    {
        int u = E[i].second.first;
        int v = E[i].second.second;
        if(!mesmoConjunto(u,v))
        {
            resul+= E[i].first;
            unionFind(u, v);
        }
    }
    return resul;
}

int main()
{
    int N, M;
    vector< pair<int, kk > > E;
    while(cin>>N>>M && N!=0 && M!=0)
    {
        E.clear();
        for(int i=0;i<N;i++)
        {
             vecAdj[i].clear();
             Size[i]=1;
             an[i]=i;
        }
        int u, v, w;
        while(M--)
        {
             scanf("%d %d %d",&u,&v,&w);
             vecAdj[u].push_back({w, v});
             vecAdj[v].push_back({w, u});
             E.push_back({w,{u,v}});
        }
        sort(E.begin(), E.end());
        int resul = Kruskal(E);
        printf("%d\n",resul);
    }
}

