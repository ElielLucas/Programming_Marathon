#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool search(int *vet, int left, int right, int X, int*posicao)
{
    if(left<=right)
    {
        int m = (left+right)/2;
        if(X<vet[m])return search(vet,left,m-1,X,posicao);
        else if(X>vet[m])return search(vet,m+1,right,X,posicao);

        int i;
        for(i=m;vet[i-1]==vet[i];i--);
        *posicao=i+1;
        return true;
    }
    return false;
}
int main()
{
   int N, Q, cont=1;

   while(scanf("%d %d",&N,&Q) && N && Q)
   {
       int vet[N];
       for(int i=0;i<N;i++)
           scanf("%d",&vet[i]);

       sort(vet,vet+N);

       printf("CASE# %d:\n",cont++);
       while(Q--)
       {
           int x, saida=0;
           scanf("%d",&x);
           if(search(vet,0,N-1,x,&saida))
               printf("%d found at %d\n",x,saida);
           else
               printf("%d not found\n",x);
       }
   }

}

