#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

class node
{
public:
    node();
    int D;
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
    void inOrder(node* R,vector<int> &saida);
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

void tree::inOrder(node* R, vector<int> &saida)
{
    if(R)
    {
        inOrder(R->left,saida);
        saida.push_back(R->D);
        inOrder(R->right,saida);
    }
}
void tree::preOrder(node* R, vector<int> &saida)
{
    if(R)
    {
        saida.push_back(R->D);
        preOrder(R->left,saida);
        preOrder(R->right,saida);
    }
}
void tree::posOrder(node* R, vector<int> &saida)
{
    if(R)
    {
        posOrder(R->left,saida);
        posOrder(R->right,saida);
        saida.push_back(R->D);
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
    int C,N;
    scanf("%d",&C);
    for(int k=1;k<=C;k++)
    {
        scanf("%d",&N);

        int x;
        tree T;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&x);
            T.insert(x);
        }

        printf("Case %d:\n",k);
        //preOrder
        vector<int> saida;
        T.preOrder(T.root, saida);
        printf("Pre.: ");
        printt(saida);

        //inOrder
        saida.clear();
        T.inOrder(T.root, saida);
        printf("In..: ");
        printt(saida);

        //posOrder
        saida.clear();
        T.posOrder(T.root, saida);
        printf("Post: ");
        printt(saida);
        printf("\n");
    }
}

