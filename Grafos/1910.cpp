#include <iostream>
#include<vector>
#include<queue>

using namespace std;

typedef vector<int> vi;

vi G[100002];

int bfs(int inicial, int final, int V, vector<int> blockedChannels)
{
	int dist[V+2], inf=123456789;
	for(int i=0;i<=V;i++)
		dist[i]=inf;
		
	for(int i=0;i<blockedChannels.size();i++)
		dist[blockedChannels[i]]=-1;	
		
	queue<int> fila;
	fila.push(inicial);
	dist[inicial]=0;
	
	int cont=1;
	while(!fila.empty())
	{
		int u=fila.front();
		fila.pop();
		
		int sizee=G[u].size();

		for(int i=0; i < sizee; i++)
		{
			int v=G[u][i];
		
			if(dist[v] > dist[u] + 1 && dist[u]!=-1)
			{
				dist[v]= dist[u]+1;
				fila.push(v);
			}
		}
	}
	if(dist[final]==123456789)
		return -1;
	else 
		return dist[final];
	
}

int main() 
{

    int O, D, K;
	vector<int> blockedChannels;
	while(scanf("%d %d %d",&O,&D,&K), O || D || K)
	{
		blockedChannels.clear();
		blockedChannels.resize(K);	
		for(int i=0;i<K;i++)
		{
			int channel;
			scanf("%d",&channel);
			blockedChannels[i]=channel;
		}	
		
		for(int i=0; i<100002; i++)
		{
			if(i+1<=100000)
				G[i].push_back(i + 1);
			if(i-1>=1)
				G[i].push_back(i - 1);
			if(i*2<=100000 && i*2>=1)
				G[i].push_back(i * 2);
			if(i*3<=100000 && i*3>=1)
				G[i].push_back(i * 3);
			if(i%2==0 && i/2>=1)
				G[i].push_back(i/2);	
		}
		
	    printf("%d\n",bfs(O,D,100002,blockedChannels));
						
		for(int i=0; i<100002; ++i)
			G[i].clear();
						
	}
}
