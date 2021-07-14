#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

bool visit[100000000];
class node
{
public:
    node();
    int D;
    bool visit;
    node* left;
    node* right;
    node(int d);
    static node* montaNode(int D);
};
node::node(int d)
{
    D=d;
    left=0;
    right=0;
    visit=false;
}
node* node::montaNode(int D)
{
    node * saida = new node(D);
    return saida;
}

class tree
{
public:
    tree();
    node* root;
    void insert(int x);
    void inOrder(node* R)
    {
        if(R)
        {
            inOrder(R->left);
            cout<<R->D<<" ";
            inOrder(R->right);
        }
    }
    void preOrder(node* R, vector<int> &saida);
    void posOrder(node* R, vector<int> &saida);
};

tree::tree()
{
    root=0;
}

void tree::insert(int x)
{
    node * newNode = node::montaNode(x);
    if(!root)root=newNode;
    else
    {
        node* atual = root;
        node* ant = 0;

        while(atual)
        {
            ant = atual;

            if(x > atual->D)
                atual = atual->right;
            else
                atual = atual->left;
        }
        if (x > ant->D)
            ant->right = newNode;
        else
            ant->left = newNode;
    }
}

void bfs(tree T,vector<int> &saida)
{
    queue<node *> Q;
    T.root->visit=true;
    Q.push(T.root);
    saida.push_back(T.root->D);

    while(!Q.empty())
    {
        node* u = Q.front();
        Q.pop();
        vector<node*> adj;
        if(u->left)adj.push_back(u->left);
        if(u->right)adj.push_back(u->right);

        for(int i=0;i<(int)adj.size();i++)
        {
            node* v = adj[i];

            if(!v->visit)
            {
                Q.push(v);
                saida.push_back(v->D);
                v->visit=true;
            }
        }
    }
}

void printt(vector<int> x)
{  
    int i=0;
    for(;i<(int)x.size()-1;i++)
        printf("%d ",x[i]);

    printf("%d\n",x[i]);
}

int main()
{
   int C, n;
   scanf("%d",&C);
   for(int i=1;i<=C;i++)
   {
       scanf("%d",&n);
       tree T;
       for(int j=0;j<n;j++)
       {
           int x;
           scanf("%d",&x);
           T.insert(x);
       }
       vector<int>aux;

       bfs(T,aux);

       printf("Case %d:\n",i);
       printt(aux);
       printf("\n");
   }

}

