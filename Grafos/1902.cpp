#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;

vector<int> V[1000000];
int visit[1000000];
map<string,int> indice;
void dfs(int u, int &casais)
{
    if(!visit[u])
    {
        visit[u]=1;
        for(int i=0;i<(int)V[u].size();i++)
        {
            int v = V[u][i];
            dfs(v,casais);
        }
        visit[u]=2;
    }else if(visit[u]==1)
       casais++;
}

int main()
{
   string x, y;

   int cont=0;
   while(cin>>x>>y)
   {    
       if(indice[x]==0)indice[x]= ++cont;
       if(indice[y]==0)indice[y]= ++cont;
       V[indice[x]].push_back(indice[y]);

   }
   int casais=0;
   for(int i=1;i<=cont;i++)
   {
       if(!visit[i])
           dfs(i,casais);
   }
   printf("%d\n", casais);
}

