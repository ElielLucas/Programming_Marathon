#include <iostream>
#include<vector>
#include<queue>

using namespace std;

typedef vector<int> vi;
vi G[1002];

int bfs(int inicial, int final, int sizeV, int E)
{
	int dist[sizeV+2], inf=123456789;
	for(int i=0;i<=sizeV;i++)
		dist[i]=inf;
	
	queue<int> fila;
	fila.push(inicial);
	dist[inicial]=0;
	
	while(!fila.empty())
	{
		int u=fila.front();
		fila.pop();
		
		int sizee=G[u].size();

		for(int i=1; i < sizee; i++)
		{
			int v=G[u][i];
		
			if(v != E && dist[v] > dist[u] + 1)
			{
				dist[v]= dist[u]+1;
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
		for(int i=1;i<=N;i++)
		{
			G[i].clear();
			G[i].push_back(i);
		}
		int A, B, C, R, E;

		for(int i=0;i<M;i++)
		{
			scanf("%d %d",&A,&B);

			G[A].push_back(B);
			G[B].push_back(A);
		}
		scanf("%d %d %d",&C,&R,&E);

		printf("%d\n",bfs(C,R, 1000,E));
	}
}
