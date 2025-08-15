#include<bits/stdc++.h>
using namespace std;

    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        long long Mod=1000000007;
        sort(nums.begin(),nums.end());
        long long result=0;
        auto find=[&](int start)->int{
            int l=start,r=n-1;
            while(l<r){
                int mid=l+(r-l)/2;
                if(nums[start]+nums[mid]<=target){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            return r;
        };
        for(int i=0;i<n;i++){
            if(nums[i]*2>target)break;
            int mx=find(i);
            long long sum=(long long)pow(2,(mx-i))%Mod;
            result=(result+sum)%Mod;
        }
        return result;
    }

int main() {
    vector<int> nums = {3, 5, 6, 7};
    int target = 9;
    cout << numSubseq(nums, target) << endl;
    return 0;
}