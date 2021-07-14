#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

string in,pre;
int preIndex;

class node
{
public:
    node* left;
    node* right;
    char D;
    node(char d);
    static node* montaNode(char d);
};
node::node(char d)
{
    D=d;
    left=0;
    right=0;
}
node* node::montaNode(char d)
{
    node *saida = new node(d);
    return saida;
}

node* reconstrucao(int left, int right)
{
    if(left>right)return 0;

    node * newNode = node::montaNode(pre[preIndex++]);

    if(left==right)return newNode;

    int inIndex = in.find(newNode->D);
    node* leftChild = reconstrucao(left, inIndex-1);
    node * rightChild = reconstrucao(inIndex+1, right);

    newNode->left=leftChild;
    newNode->right=rightChild;
    return newNode;
}

void posOrdem(node* R, string &saida)
{
    if(R)
    {
        posOrdem(R->left,saida);
        posOrdem(R->right,saida);
        saida+=R->D;
    }
}
int main()
{
    int N, x;
    string a,b;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&x);
        cin>>pre>>in;
        preIndex=0;
        string saida="";
        posOrdem(reconstrucao(0,x-1),saida);
        cout<<saida<<"\n";
    }
}

