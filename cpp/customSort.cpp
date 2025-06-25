#include<bits/stdc++.h>
using namespace std;
bool compair(int a,int b){
    return a>b;
}
int main(){
    vector<int> v={2,1,6,8,4,2,6};
    sort(v.begin(),v.end(),compair);
    for(auto i:v){
        cout<<i<<" ";
    }
    return 0;
}