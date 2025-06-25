#include<bits/stdc++.h>
using namespace std;
vector<int> func(vector<int> nums,int N){
    int n=nums.size();
    int l=0,r=n-1;
    while(l<r){
        if(nums[l]+nums[r]==N){
            return {nums[l],nums[r]};
        }
        else if(nums[l]+nums[r]<N){
            l++;
        }else {
            r--;
        }
    }
    return {-1,-1};
}
int main(){
    vector<int> nums={1,2,4,7,11,15};
    int N=15;
    vector<int> a=func(nums,N);
    cout<<a[0]<<" "<<a[1];
    return 0;
}