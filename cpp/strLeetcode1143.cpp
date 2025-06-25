#include<bits/stdc++.h>
using namespace std;
int longestCommonSubsequence(string text1, string text2) {
    int m=text1.size();
    int n=text2.size();
    vector<vector<int>> grid(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0&&j!=0)grid[i][j]=grid[i][j-1];
            else if(i!=0&&j==0)grid[i][j]=grid[i-1][j];
            else if(i!=0&&j!=0)grid[i][j]=max(grid[i-1][j],grid[i][j-1]);
            if(text1[i]==text2[j]){
                //grid[i][j]++;
                if(i==0||j==0)grid[i][j]=1;
                else grid[i][j]=grid[i-1][j-1]+1;
            }
        }
    }
    cout<<0<<"  ";
    for(int j=0;j<n;j++){
        cout<<text2[j]<<"  ";
    }cout <<endl;
    for(int i=0;i<m;i++){
        cout<<text1[i]<<"  ";
        for(int j=0;j<n;j++){
            if(grid[i][j]<10)
            cout<<grid[i][j]<<"  ";
            else cout<<grid[i][j]<<" ";
        }cout<<endl;
    }
    return grid[m-1][n-1];
}
int main(){
    //int ans=longestCommonSubsequence("bsbininm","jmjkbkjkv");
    //int ans=longestCommonSubsequence("oxcpqrsvwf","shmtulqrypy");
    //int ans=longestCommonSubsequence("abcde","ace");
    int ans=longestCommonSubsequence("bmvcnwrmxcfcxabkxcvgbozmpspsbenazglyxkpibgzq","bmpmlstotylonkvmhqjyxmnqzctonqtobahcrcbibgzg");
    cout<<ans<<endl;
    return 0;
}