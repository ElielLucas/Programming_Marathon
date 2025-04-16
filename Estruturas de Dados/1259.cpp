#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int main(){
   int N;
   scanf("%d", &N);
   
   vector<int> values;

   for (int i = 0; i < N; i++){
       int x;
       scanf("%d", &x);
       values.push_back(x);
   }

   vector<int> even, odd;

   for (int i = 0; i < values.size(); i++){
        if (values[i] % 2 == 0)
            even.push_back(values[i]);
        else
            odd.push_back(values[i]);
   }

   sort(even.begin(), even.end());
   sort(odd.begin(), odd.end(), greater<int>());

   vector<int> output = even;

   output.insert(output.end(), odd.begin(), odd.end());
   for (int i = 0; i < output.size(); i++){
        printf("%d\n", output[i]);
   }
}