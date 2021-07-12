#include <iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

typedef pair<int,int> q;
typedef vector<q> vi;
vi G[510];
int N, M, K,Q;

int dijkstra(int inicial,int destino, int sizeV)
{
	int dist[sizeV+10], inf=123456789;
	for(int i=0;i<=sizeV;i++)
		dist[i]=inf;
	
	priority_queue < pair<int, int>,
			vector<pair<int, int> >, greater<pair<int, int> > > fila;

	dist[inicial]=0;
	fila.push(make_pair(dist[inicial],inicial));
	
	while(!fila.empty())
	{
		pair<int,int> pair=fila.top();
		int u=pair.second;
		fila.pop();
		
		int size=G[u].size();
		for(int i=0; i < size; i++)
		{
			int v, custo;
			v=G[u][i].first;
			custo=G[u][i].second;
			
			if(dist[v] > dist[u] + custo)
			{
				dist[v]= dist[u]+custo;
				fila.push(make_pair(dist[v],v));
			}				
		}
	}	
    return dist[destino];
}

int main()
{
        while(scanf("%d %d",&N,&M) && (N || M))
        {
            int u,v,k;
            for(int i=0;i<=N;i++)
                G[i].clear();
                
            for(int i=0;i<M;i++)
            {
                scanf("%d %d %d",&u,&v,&k);
                int ok=true;
                for(int i=0;i<G[v].size() && ok;i++)
                {
                    if(G[v][i].first==u)
                    {
                        G[v][i].second=0;
                        ok=false;
                    }
                }
                if(ok)G[u].push_back(make_pair(v,k)); 
                else G[u].push_back(make_pair(v,0)); 
            }
            
            int K, o, d;
            scanf("%d",&K);
            while(K--)
            {
                scanf("%d %d",&o,&d);
                int resul=dijkstra(o,d,500);
                if(resul!=123456789)printf("%d\n",resul);
                else printf("Nao e possivel entregar a carta\n");
            }
            printf("\n");
        } 
}
