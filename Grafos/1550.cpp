#include <iostream>
#include<vector>
#include<queue>

using namespace std;

typedef vector<int> vi;

vi G[10002], vec;
int E;

int potencia(int x, int y)
{
	int acc = x;
	
	if(y == 0) return 1;
	
	while(--y > 0)
		acc*= x;
		
	return acc;
}
int invert(int n)
{
	int num=n,dig[5],i,j;

	for(i=0; num; i++)
	{  
		dig[i] = num % 10;
		num /= 10;
	}
	
	for(j=0; j<i; j++)
    	num += dig[j] * potencia(10, (i-j-1)); 
    
    return num;
}

int bfs(int inicial, int final, int V)
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
			int v=G[u][i];
		
			if(dist[v] > dist[u] + 1)
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
	int T;
	scanf("%d",&T);
	
	while(T--)
	{
		int A, B;
		scanf("%d %d",&A,&B);
		
		for(int i=0; i<10002; i++)
		{
			G[i].push_back(i + 1);
			G[i].push_back(invert(i));
		}
	
		printf("%d\n",bfs(A,B,10002));	
		for(int i=0; i<10002; ++i)
			G[i].clear();
				
	}
}
