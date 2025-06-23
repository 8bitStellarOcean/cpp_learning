#include<bits/stdc++.h>
using namespace std;
int candy(vector<int>& ratings) {
    int n=ratings.size();
    vector<int> ans(n,1);
    for(int i=0;i<n;i++){
        if(i-1>=0){
            if(ratings[i]>ratings[i-1]){
                ans[i]=ans[i-1]+1;
            }
        }
    }
        for(int i=n-1;i>=0;i--){
            if(i+1<n){
                if(ratings[i]>ratings[i+1]){
                    if(ans[i]<=ans[i+1]){
                        ans[i]=ans[i+1]+1;
                    }
                }
            }
        }
    for(int i=0;i<n;i++){
        cout<<ratings[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    int result=0;
    for(auto& a:ans){
        result+=a;
    }
    return result;
}
int main(){
    int result=0;
    vector<int> ratings={1,3,2,2,1};
    vector<int> ratings2={1,2,87,87,87,2,1};
    result=candy(ratings2);
    cout<<result<<endl;
    return 0;
}