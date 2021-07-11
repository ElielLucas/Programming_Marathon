#include <iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;


typedef vector<int> vi;
vi G[110];

int N, M, c;
typedef pair<int,bool> q;
vector<q>analise;


void bfs(int inicial, int sizeV)
{
	int dist[sizeV+10], inf=123456789;
	for(int i=0;i<=sizeV;i++)
		dist[i]=inf;
	
	queue<int> fila;
	fila.push(inicial);
	dist[inicial]=0;
	
	while(!fila.empty())
	{
		int u=fila.front();
		fila.pop();
		
		for(int i=1; i < G[u].size(); i++)
		{
			int v=G[u][i];
			if(dist[v] > dist[u] + 1)
			{
				dist[v]= dist[u]+1;
				fila.push(v);
			}
		}
	}	

    for(int i=1;i<=N;i++)
    {
        if(dist[i]==123456789)
        {
            pair<int,bool> x;
            x.first=i;
            x.second=false;
            analise.push_back(x);
            c++;
        }
    }	
}
bool bfs2(int inicial, int destino, int sizeV)
{
	int dist[sizeV+10], inf=123456789;
	for(int i=0;i<=sizeV;i++)
		dist[i]=inf;
	
	queue<int> fila;
	fila.push(inicial);
	dist[inicial]=0;
	
	while(!fila.empty())
	{
		int u=fila.front();
		fila.pop();
		
		for(int i=1; i < G[u].size(); i++)
		{
			int v=G[u][i];
			if(dist[v] > dist[u] + 1)
			{
				dist[v]= dist[u]+1;
				fila.push(v);
			}
		}
	}	
    if(dist[destino]!=123456789)
    {
        for(int i=0;i<analise.size();i++)
        {
            if(analise[i].first==destino)analise[i].second=true;
        }
        return true;
    }
    else return false;  
}
int main()
{
    int T, cont=1;
    scanf("%d",&T);
	while(T--)
	{	
        analise.clear();
        scanf("%d",&N);
        scanf("%d",&M);
		
		for(int i=1;i<=N;i++)
		{
            G[i].clear();
			G[i].push_back(i);
		}
        int x,y;
        for(int i=0;i<M;i++)
		{
			scanf("%d %d",&x,&y);
            G[x].push_back(y);	
            G[y].push_back(x);	
		}
        c=0;
        bfs(1,100);
        vector<bool> aux;
        for(int i=0;i<analise.size();i++)
        {
            aux.clear();
            for(int j=i+1;j<analise.size();j++)
            {
                if(analise[i].second==0 && analise[j].second==0)aux.push_back(bfs2(analise[i].first,analise[j].first,100));
            } 
            for(int j=0;j<aux.size();j++)
                if(aux[j])c--;   
        }
        if(c==0)printf("Caso #%d: a promessa foi cumprida\n",cont);
        else printf("Caso #%d: ainda falta(m) %d estrada(s)\n",cont,c);
		cont++;
	}
}

