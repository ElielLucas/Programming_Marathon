#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int matrix[210][210][26];
string intToChar(int x)
{
    char aux= x + 96;
    string saida="";
    saida+=aux;
    return saida;
}
int charToInt(char x)
{
    int saida= x - 96;
    return saida;
}
void floyd_warshall(int N)
{
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                for(int h=1;h<=26;h++)
                {
                    matrix[i][j][h] = min(matrix[i][k][h] + matrix[k][j][h], matrix[i][j][h]);
                }
            }
        }
    }
}

string devolveEmpresas(int* x)
{
    string saida="";
    for(int i=1;i<=26;i++)
        if(x[i] && x[i]!=99999999)saida+=intToChar(i);

    if(saida=="")saida="-";
    return saida;
}
int main()
{
    int N;

    while(scanf("%d",&N) && N)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                for(int k=1;k<=26;k++)
                    matrix[i][j][k]=99999999;
            }
        }

        int u, v;
        string empresas;
        while(scanf("%d %d",&u,&v) && u && v)
        {
            cin>>empresas;
            for(int i=0;i<(int)empresas.size();i++)
                matrix[u][v][charToInt(empresas[i])]=1;
        }

        floyd_warshall(N);

        while(scanf("%d %d",&u,&v) && u && v)       
            cout<<devolveEmpresas(matrix[u][v])<<"\n";
        
        printf("\n");
    }
}

