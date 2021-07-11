#include <iostream>
#include<utility>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int,int> pi;
typedef pair<int,pi>pii;

typedef vector<pii> vi;

vi G1[102],G2[102];

int bfs(int inicial, int final, int V, vi* G)
{
	int dist[V+2], inf=123456789;
	for(int i=0;i<=V;i++)
		dist[i]=inf;
			
	queue<int> fila;
	fila.push(inicial);
	dist[inicial]=0;
	
	while(!fila.empty())
	{
		int u=fila.front();
		fila.pop();
		
		int sizee=G[u].size();
		
		for(int i=0; i < sizee; i++)
		{
			pii pairDuplo=G[u][i];
			int v=pairDuplo.first;
		
			if(dist[v] > dist[u] + pairDuplo.second.second)
			{
				dist[v] = dist[u]+ pairDuplo.second.second;
				fila.push(v);
			}
		}
	}
	return dist[final];
}
int main() 
{

    int N, M;
	
	while(scanf("%d %d",&N,&M)!=EOF)
	{	
		for(int i=0;i<M;i++)
		{
			int A, B, T, R;
			pii pairDuplo;
			scanf("%d%d%d%d",&A,&B,&T,&R);
			pairDuplo=make_pair(B,make_pair(T,R));
			if(T==0)
				G1[A].push_back(pairDuplo);
		  	else if(T==1)
		  		G2[A].push_back(pairDuplo);
		}	
		
		int onibus=bfs(1,N,100,G1);
		int aviao=bfs(1,N,100,G2);
		
		if(onibus<aviao)
			printf("%d\n",onibus);
		else if(onibus>aviao)
			printf("%d\n",aviao);
		
		for(int i=0; i<102; ++i)
		{
			G1[i].clear();
			G2[i].clear();
		}					
	}
}
