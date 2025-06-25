#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    swap(arr[0], arr[4]);
    for(auto a:arr){
        cout<<a<<" ";
    }
    return 0;
}