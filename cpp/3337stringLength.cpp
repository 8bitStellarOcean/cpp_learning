// 动态规划+空间优化 leetcode超时
#include<bits/stdc++.h>
using namespace std;
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        long long mod=1000000007;
        vector<vector<long long>> dp(2,vector<long long>(26,0));
        for(auto& a:dp[0]){
            a=1;
        }
        //dp[1].assign(nums.begin(),nums.end());
        for(int i=1;i<=t;i++){
            dp[1].assign(26,0);
            for(int j=0;j<26;j++){
                for(int k=nums[j];k>0;k--){
                    dp[1][j]+=dp[0][(j+k)%26];
                    if(dp[1][j]>LLONG_MAX/2)dp[1][j]=dp[1][j]%mod;
                }
            }
            dp[0].assign(dp[1].begin(),dp[1].end());
        }
        long long result=0;
        for(auto a:s){
            result=result+dp[1][a-'a'];
            if(result>LLONG_MAX/2)result=result%mod;
        }
        return result%mod;
    }
int main(){
    auto s="abcyy";
    int t=2;
    vector<int> nums={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2};
    int a=lengthAfterTransformations(s,t,nums);
    cout<<a<<endl;
    return 0;
}