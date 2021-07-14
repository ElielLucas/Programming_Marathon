#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> V[500000], G[500000];
bool visitV[500000], visitG[500000];
vector<pair<int,int>> top;
void dfs(int u)
{
    for(int i=0;i<(int)G[u].size();i++)
    {
        int v = G[u][i];
        if(!visitG[v])
        {
            visitG[v]=true;
            dfs(v);
        }
    }
}

void topological(int u, int &temp)
{
    temp++;
    for(int i=0;i<(int)V[u].size();i++)
    {
        int v = V[u][i];
        if(!visitV[v])
        {
            visitV[v]=true;
            topological(v, temp);
        }
    }
    temp++;
    top.push_back({temp, u});
}

bool decrescente(pair<int,int> &a, pair<int,int> &b)
{
    if(a.first>b.first)return true;
    return false;
}
int main()
{
    int N, u, v;

    scanf("%d",&N);

    for(int i=0; i<N;i++)
    {
        scanf("%d %d",&u, &v);

        V[u].push_back(v);
        G[v].push_back(u);
    }

    int temp=0;
    for(int i=1; i<=N; i++)
    {
        if(!visitV[i])
        {
            visitV[i]=true;
            topological(i,temp);
        }
    }

    sort(top.begin(), top.end(), decrescente);

    int saida=0;
    for(int i=1; i<=N; i++)
    {
        int u = top[i-1].second;
        if(!visitG[u])
        {
            visitG[u]=true;
            dfs(u);
            saida++;
        }
    }
    if(saida==1)printf("S\n");
    else printf("N\n");
}

