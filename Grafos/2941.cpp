#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int matrixAdj[500][500], matrixCusto[500][500];
int ans[500], sizee[500], saida=0;
vector<pair<int,pair<int,int> > > firstKruskal, resulFirstKruskal, secondKruskal;
int find(int u)
{
    if(u!=ans[u])return ans[u]=find(ans[u]);
    return u;
}

void unionFind(int u,int v)
{
    int rU = find(u);
    int rV = find(v);

    if(sizee[rU]>sizee[rV])
    {
        ans[rV]=rU;
    }else
    {
        ans[rU]=rV;
        if(sizee[rU]==sizee[rV])
            sizee[rV]++;
    }
}

void kruskal(int N, int num)
{
    if(num==1)
    {
        for(int i=0;i<(int)firstKruskal.size();i++)
        {
            int u=firstKruskal[i].second.first;
            int v=firstKruskal[i].second.second;
            int w=firstKruskal[i].first;
            if(find(u)!=find(v))
            {
                unionFind(u,v);                             
            }else saida+=w;
        }
    }else
    {
        for(int i=0;i<(int)secondKruskal.size();i++)
        {
            int u=secondKruskal[i].second.first;
            int v=secondKruskal[i].second.second;
            int w=secondKruskal[i].first;
            if(find(u)!=find(v))
            {
                saida+=w;
                unionFind(u,v);
            }
        }
    }
}

bool comp(pair<int,pair<int,int> > &a, pair<int,pair<int,int> >&b)
{
    return a.first>b.first;
}

int main()
{
   int N, C;
   scanf("%d",&N);
   for(int i=1;i<=N;i++)
   {
       ans[i]=i;
       sizee[i]=1;
   }
   for(int i=1;i<=N;i++)
   {
      for(int j=1;j<=N;j++)
      {
          scanf("%d",&C);
          if(i>j && C)
             matrixAdj[j][i]=1;
          else if(i<j)
            matrixCusto[i][j]=C;
      }
   }

   for(int i=1;i<=N;i++)
   {
      for(int j=1;j<=N;j++)
      {
          if(i<j)
          {
              int w = matrixCusto[i][j];
              if(matrixAdj[i][j]==1)
                  firstKruskal.push_back({w,{i,j}});
              else
                  secondKruskal.push_back({w,{i,j}});
          }
      }
   }
   sort(firstKruskal.begin(), firstKruskal.end(),comp);

   kruskal(N,1);

   sort(secondKruskal.begin(), secondKruskal.end());

   kruskal(N,2);

   printf("%d\n",saida);
}

