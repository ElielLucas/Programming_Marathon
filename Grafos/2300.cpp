#include <iostream>
#include<vector>
using namespace std;

typedef vector<int> ii;
ii vecAdj[110];
bool visit[110];

void dfs(int u, int &cont)
{
    for(int i=0;i<(int)vecAdj[u].size();i++)
    {       
        int k=vecAdj[u][i];
        if(!visit[k])
        {
             cont++;
             visit[k]=true;
             dfs(k,cont);
        }
    }      
}

int main()
{
    int E, L, cont=1;
    while(scanf("%d %d",&E,&L) && E!=0 && L!=0)
    {
        for(int i=1;i<=E;i++)
        {
            vecAdj[i].clear();
            visit[i]=false;                     
        }
        int aux1, aux2;
        while(L--)
        {
            scanf("%d %d",&aux1, &aux2);
            vecAdj[aux1].push_back(aux2);
            vecAdj[aux2].push_back(aux1);
        }       
        visit[1]=true;
        int nodes=1;
        dfs(1,nodes);

        printf("Teste %d\n",cont++);
        if(nodes==E)printf("normal\n");
        else printf("falha\n");
        printf("\n");
    }
}

