#include<iostream>
#include<vector>
#include<set>
#include<sstream>

using namespace std;


int main(){
    int N;

    scanf("%d", &N);
    std::cin.ignore();
    set<string> shop_list;

    while(N--){
        shop_list.clear();
        string line = "", word;

        getline(cin, line);

        stringstream ss(line);

        while(ss>>word){
            shop_list.insert(word);
        }

        for (auto it = shop_list.begin(); it != shop_list.end(); it++){
            if (next(it) != shop_list.end())
                cout<<*it<<" ";
            else
                cout<<*it;
        }
        printf("\n");
    }
}