#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(){

    int N, M;

    scanf("%d", &N);

    while (N--){
        scanf("%d", &M);
        vector<int> P(M);

        for (int i = 0; i < M; i++)
            scanf("%d", &P[i]);
        
        vector<int> cp = P;

        sort(P.begin(), P.end(), greater<int>());
        
        int output = 0;

        for (int i = 0; i < cp.size(); i++)
            if (P[i] == cp[i])
                output++;

        printf("%d\n", output);
    }
}