#include <iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int volume(int x, int y, int z)
{
    return (x*y*z);
}

bool comp(pair<int,int> &a, pair<int,int>&b)
{
    if(a.first>b.first)return true;
    else if(a.first<b.first)return false;
    else
    {
        if(a.second<b.second)return true;
        if(a.second>b.second)return false;
        return true;
    }
}
bool comp2(int &a, int&b)
{
    return a<b;
}

int main()
{
    int t, n, k, I, H, W, L;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        pair<int,int> vec[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&I,&H,&W,&L);
            int vol = volume(H,W,L);
            vec[i]={vol, I};
        }

        sort(vec, vec+n, comp);

        int resul[k];
        for(int i=0;i<k;i++)
            resul[i]=vec[i].second;

        sort(resul,resul+k,comp2);

        int i=0;
        for(; i<k-1;i++)
            printf("%d ",resul[i]);
        printf("%d\n",resul[i]);
    }

}

