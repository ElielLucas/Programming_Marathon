#include<iostream>
#include<stack>

using namespace std;



int main(){

    int N;
    string inp;
    scanf("%d", &N);

    stack<char> p;
    while(N--){
        while(!p.empty())
            p.pop();
        
        cin>>inp;
        
        int output = 0;
        for (char c: inp)
        if (c == '<')
            p.push(c);
        else if (c == '>' && !p.empty()){
            p.pop();
            output++;
        }

        printf("%d\n", output);
    }
}