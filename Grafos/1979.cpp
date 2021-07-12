#include <iostream>
#include<vector>
#include<set>
#include<string>
#include<sstream>
using namespace std;
typedef set<int> ii;
ii vecAdj[110];
int visit[110];

bool dfs(int u, int c)
{
   visit[u] = c;
   for (auto i = vecAdj[u].begin(); i !=vecAdj[u].end(); i++)
   {
      int v = *i;
      if (visit[v] == -1 && !dfs(v,1-c))
            return false;
      else if (visit[v] == c)
            return false;
   }
   return true;
}

int main()
{
    int n;
    while(cin>>n && n!=0)
    {
        for(int i=1;i<=n;i++)
        {
            vecAdj[i].clear();
            visit[i]=-1;
        }
        int u,v;
        stringstream ss;
        string friends;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&u);

            getchar();
            getline(cin,friends);
            ss << friends;
            while(ss>>v)
            {
                vecAdj[u].insert(v);
                vecAdj[v].insert(u);
            }
            ss.clear();
        }        
        bool saida=false;
        for(int i=1;i<=n;i++)
            if(visit[i]==-1)
                saida=dfs(i,0);

        if(saida)printf("SIM\n");
        else printf("NAO\n");
    }
}

