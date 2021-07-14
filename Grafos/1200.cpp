#include <iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;


char tree[1000000];
bool  ok[1000000];
void insert(int root, char dado)
{
    if(!ok[root])
    {
        tree[root]=dado;
        ok[root]=true;
    }
    else
    {
        if(dado<tree[root])insert(2*root,dado);
        else if(dado>tree[root])insert((2*root)+1,dado);
    }
    return;
}

void preOrdem(int root,string &saida)
{
    if(ok[root])
    {
        saida+=tree[root];
        preOrdem(2*root,saida);
        preOrdem((2*root)+1,saida);
    }
}
void inOrdem(int root,string &saida)
{
    if(ok[root])
    {
        inOrdem(2*root,saida);
        saida+=tree[root];
        inOrdem((2*root)+1,saida);
    }
}
void posOrdem(int root,string &saida)
{
    if(ok[root])
    {
        posOrdem(2*root,saida);
        posOrdem((2*root)+1,saida);
        saida+=tree[root];
    }
}
void printt(string x)
{
    int i=0;
    for(;i<(int)x.size()-1;i++)
        printf("%c ",x[i]);

    printf("%c\n",x[i]);
}

bool search(int root, char x)
{
    if(!ok[root])return false;

    if(tree[root]==x)return true;

    if(x<tree[root])search(2*root,x);
    else search((2*root)+1,x);
}
int main()
{
    string op, saida;
    memset(ok,false,1000000);
    while(cin>>op)
    {
        if(op=="I")
        {
            char x;
            cin>>x;
            insert(1,x);
        }else if(op=="PREFIXA")
        {
            saida="";
            preOrdem(1,saida);
            printt(saida);
        }else if(op=="INFIXA")
        {
            saida="";
            inOrdem(1,saida);
            printt(saida);
        }else if(op=="POSFIXA")
        {
            saida="";
            posOrdem(1,saida);
            printt(saida);
        }else if(op=="P")
        {
            char x;
            cin>>x;
            if(search(1,x))printf("%c existe\n",x);
            else printf("%c nao existe\n",x);
        }

    }
}

