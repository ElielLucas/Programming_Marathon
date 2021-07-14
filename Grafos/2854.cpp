#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

map<string,vector<string>> V;
map<string,bool> visitV, visitG;
vector<pair<int,string>> top;
void dfs(string u)
{
    vector<string> aux = V[u];
    for(int i=0;i<(int)aux.size();i++)
    {
        string v = aux[i];
        if(!visitG[v])
        {
            visitG[v]=true;
            dfs(v);
        }
    }
}

void topological(string u, int &temp)
{
    temp++;
    vector<string> aux = V[u];
    for(int i=0;i<(int)aux.size();i++)
    {
        string v = aux[i];
        if(!visitV[v])
        {
            visitV[v]=true;
            topological(v, temp);          
        }
    }
    temp++;
    top.push_back({temp, u});
}

bool decrescente(pair<int,string> &a, pair<int,string> &b)
{
    if(a.first>b.first)return true;
    return false;
}
int main()
{
    int N, M;
    string u, parentesco, v;
    vector<string> a;
    scanf("%d%d",&N,&M);

    while(M--)
    {
        cin>>u>>parentesco>>v;
        V.insert({u,a});
        V.insert({v,a});

        V[u].push_back(v);
        V[v].push_back(u);
    }

    int temp=0;
    for(auto i =V.begin(); i != V.end(); i++)
    {
        string u = i->first;
        if(!visitV[u])
        {
            visitV[u]=true;
            topological(u,temp);
        }
    }

    sort(top.begin(), top.end(), decrescente);

    int saida=0;
    for(auto i =V.begin(); i != V.end(); i++)
    {
        string u = i->first;
        if(!visitG[u])
        {
            saida++;
            dfs(u);
        }
    }
    printf("%d\n",saida);
}

