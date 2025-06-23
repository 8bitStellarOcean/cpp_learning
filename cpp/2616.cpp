#include<bits/stdc++.h>
using namespace std;
int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        if(p==0||n==1)return 0;
        sort(nums.begin(),nums.end());
        vector<int> diff(n,0);
        int mx=0;
        for(int i=1;i<n;i++){
            diff[i]=nums[i]-nums[i-1];
            mx=max(mx,diff[i]);
        }
        for(int i=1;i<n;i++){
            cout<<diff[i]<<" ";
        }cout<<endl;
        auto is=[&](int mid){
            vector<int> dp(n,0);
            if(diff[1]<=mid){
                dp[1]=1;
            }
            for(int i=2;i<n;i++){
                if(diff[i]<=mid){
                    dp[i]=max(dp[i-1],dp[i-2]+1);
                }else dp[i]=dp[i-1];
            } 
            for(int i=0;i<n;i++){
                cout<<dp[i]<<" ";
            }cout<<" ";
            return dp[n-1]>=p;
        };
        int left=0,right=mx;
        while(left<right){
            int mid=(left+right)>>1;
            cout<<left<<" "<<mid<<" "<<right<<"   ";
            if(is(mid)){
                right=mid;
            }else{
                left=mid+1;
            }
            cout<<endl;
        }
        return left;
    }
int main(){
    vector<int> num={10,1,2,7,1,3};
    int p=2;
    cout<<minimizeMax(num,p)<<endl;
    return 0;
    }