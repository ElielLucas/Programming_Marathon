#include <iostream>
#include <algorithm>
#include<vector>
#include<sstream>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, string> iis;

bool compare(iis &a, iis &b){
    if ((a.first.first == b.first.first) && (a.first.second < b.first.second))
        return true;
    
    return (a.first.first < b.first.first);
}

int main(){

    int N;

    scanf("%d", &N);

    cin.ignore();

    vector<iis> st;
    while (N--){
        st.clear();
        string line, w;

        getline(cin, line);
        
        istringstream iss(line);
        
        int aux = 0;
        while (iss >> w){
            st.push_back({{w.size()*-1, aux}, w});
            aux++;
        }
    
        string output = "";
        sort(st.begin(), st.end(), compare);

        aux = 1;
        for (iis w : st){
           output += w.second;

           if (aux < st.size())
                output += " ";
           else 
                output += "\n";

           aux++;
        }

        cout<<output;
    }
}