#include<iostream>
#include<queue>

using namespace std;

int main(){

    int N;
    queue<int> q;

    while (cin>>N && N){
        while (!q.empty())
            q.pop();

        for (int i = 0; i < N; i++)
            q.push(i + 1);
        
        printf("Discarded cards: ");

        while(q.size() >= 2){
            if (q.size() == 2)
                printf("%d", q.front());
            else
                printf("%d, ", q.front());
            
            q.pop();
            q.push(q.front());
            q.pop();
        }

        printf("\nRemaining card: %d\n", q.front());
    }
}