#include <iostream>
#include<utility>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int,int> pi;
typedef pair<int,pi>pii;

typedef vector<pii> vi;

vi G[10002];

pi bfs(int inicial, int final,int tempoMinimo, int V)
{
	int inf=123456789;
	pi dist[V+2];
	for(int i=0;i<=V;i++)
	{
		dist[i]=make_pair(inf,0);
	}		
	queue<int> fila;
	fila.push(inicial);
	dist[inicial]=make_pair(0,0);
	
	while(!fila.empty())
	{
		int u=fila.front();
		fila.pop();
		
		int sizee=G[u].size();
		
		for(int i=0; i < sizee; i++)
		{
			pii pairDuplo=G[u][i];
			int v=pairDuplo.first;
		
			if(dist[v].first > dist[u].first + pairDuplo.second.first && dist[u].second+ pairDuplo.second.second<=tempoMinimo)
			{
				dist[v].first = dist[u].first+ pairDuplo.second.first;
				dist[v].second= dist[u].second+ pairDuplo.second.second;
				fila.push(v);
			}else if(dist[v].first == dist[u].first + pairDuplo.second.first && dist[u].second+ pairDuplo.second.second<=tempoMinimo)
			{
				if(dist[v].second > dist[u].second + pairDuplo.second.second)
				{
					dist[v].first = dist[u].first+ pairDuplo.second.first;
					dist[v].second= dist[u].second+ pairDuplo.second.second;
					fila.push(v);
				}
			}
		}
	}
	pi flag;
	if(dist[final].first==123456789)
	{
		flag=make_pair(-2,-2);
		return flag;
	}else return dist[final];
}

int main() 
{
    int N, M,cont=1;
	
	while(scanf("%d %d",&N,&M), N)
	{	
		printf("Instancia %d\n",cont);
		for(int i=0;i<M;i++)
		{
			int X, Y, C, T;
			pii pairDuplo;
			scanf("%d%d%d%d",&X,&Y,&C,&T);
			pairDuplo=make_pair(Y,make_pair(C,T));

			G[X].push_back(pairDuplo);
		}
		
		int K;
		scanf("%d",&K);
		while(K--)
		{
			int A,B,tempoMinimo;
			pi resul;
			scanf("%d%d%d",&A,&B,&tempoMinimo);
			
			resul=bfs(A,B,tempoMinimo,10002);
				
			if(resul.first==-2)
			{
				printf("Impossivel\n");
			}	
			else printf("Possivel - %d km, %d min\n",resul.first,resul.second);		
		}
		for(int i=0; i<10002; ++i)
		{
			G[i].clear();		
		}
		printf("\n");	
		cont++;				
	}
}
