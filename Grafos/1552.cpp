#include<iostream>
#include<map>
#include<algorithm>
#include<math.h>
#include <queue>
using namespace std;

typedef pair<double,int> seila;
struct comp
{
   bool operator () (seila a, seila b)
   {
      return a.first > b.first;
   }
};
vector<seila> vec;
priority_queue<seila, vector<seila>, comp> order;

double d[510], X[510], Y[510];
bool visit[510];
double prim(int N)
{
    order.push({0, 1});
    double sum = 0;
    while (!order.empty())
    {
        seila elem = order.top();
        order.pop();

        int u = elem.second;
        double W = elem.first;

        if (visit[u]) continue;

        visit[u] = 1;
        sum += W;
        for(int i=1; i<=N;i++)
        {
            if(i!=u && !visit[i])
            {
                int v = i;
                W = sqrt(pow((X[u]-X[v]),2)+pow((Y[u]-Y[v]),2));
                order.push({W, v});
            }
        }
    }
    return sum;
}
int main()
{
    int C, N;
    double x, y;
    scanf("%d",&C);
    while(C--)
    {
        scanf("%d",&N);
        for(int i=1;i<=N;i++)
        {        
            scanf("%lf %lf", &x, &y);
            X[i]=x;
            Y[i]=y;
            visit[i]=false;                                                           
        }
        printf("%.2lf\n",prim(N)/100);
    }
}

