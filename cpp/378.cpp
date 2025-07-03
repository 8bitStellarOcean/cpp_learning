#include<bits/stdc++.h>
using namespace std;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        auto getnum = [&](int target) {
            int i = 0, j = n - 1;
            int num = 0;
            while (i < m && j >= 0) {
                if (target >= matrix[i][j]) {
                    num += j + 1;
                    i++;
                } else {
                    j--;
                }
            }
            return num;
        };
        int mx=matrix[m-1][n-1];
        int mi=matrix[0][0];
        while(mi<mx){
            int mid=mi+((mx-mi)>>1);
            int num=getnum(mid);
            if(num>=k){
                mx=mid;
            }else{
                mi=mid+1;
            }
        }
        return mi;
    }

int main(){
    vector<vector<int>> matrix={{1,5,9},{10,11,13},{12,13,15}};
    int k=8;
    cout<<kthSmallest(matrix,k)<<endl;
    return 0;
}