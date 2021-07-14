#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<pair<int,pair<int,int> > > order;
int ans[100000], Size[100000], qnt;
int find(int u)
{
    if(u!=ans[u])return ans[u]=find(ans[u]);
    return u;
}

void unionFind(int u,int v)
{
    int rU = find(u);
    int rV = find(v);

    if(Size[rU]>Size[rV])
    {
        ans[rV]=rU;
    }else
    {
        ans[rU]=rV;
        if(Size[rU]==Size[rV])
            Size[rV]++;
    }
}

long long kruskal(int N)
{
    long long saida=0;

    for(int i=1;i<=N;i++)
    {
        ans[i]=i;
        Size[i]=1;
    }
    for(int i=0;i<(int)order.size();i++)
    {
        int u=order[i].second.first;
        int v=order[i].second.second;
        int w=order[i].first;
        if(find(u)!=find(v))
        {
            saida+=w;
            qnt--;
            unionFind(u,v);
        }
    }
    return saida;
}

int main()
{
    int N, K, j, w;
    scanf("%d",&N);
    qnt=N;
    for(int i=1;i<=N-1;i++)
    {
        scanf("%d",&K);
        while(K--)
        {
            scanf("%d %d",&j,&w);
            order.push_back({w,{i,j}});
        }
    }
    sort(order.begin(), order.end());
    long long saida =kruskal(N);

    printf("%d %lld\n",qnt, saida);
}

