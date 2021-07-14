#include<iostream>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int valor[300], W[300],pac, pd[300][51];

int knap(int id, int w)
{
    if(id>=pac)return 0;
    if(pd[id][w]!=-1)return pd[id][w];

    if(W[id]>w)return pd[id][w] = knap(id+1,w);

    int p1 = valor[id] + knap(id+1, w - W[id]);
    int p2 = knap(id+1, w);


    return pd[id][w] = max(p1,p2);
}

vector<int> elem;

void rec(int id, int w)
{
    if(id>=pac)return;

    if(w<W[id])return rec(id+1,w);

    int p1 = valor[id] + knap(id+1, w - W[id]);

    if(pd[id][w] == p1)
    {
        elem.push_back(id);
        return rec(id+1,w-W[id]);
    }
    return rec(id+1,w);
}

int peso()
{
    int peso=0;
    for(int i=0;i<(int)elem.size();i++)
        peso+=W[elem[i]];

    return peso;
}

int main()
{
    int N, total=0;
    scanf("%d",&N);
    while(N--)
    {
        elem.clear();
        scanf("%d",&pac);
        for(int i=0;i<pac;i++)
        {
            scanf("%d %d",&valor[i], &W[i]);
            total+=valor[i];
        }

        for(int i=0;i<pac;i++)
            for(int j=0;j<=50;j++)
                pd[i][j]=-1;

        printf("%d brinquedos\n",knap(0,50));
        rec(0,50);
        printf("Peso: %d kg\n",peso());
        printf("sobra(m) %d pacote(s)\n",pac-elem.size());
        printf("\n");
    }
}


