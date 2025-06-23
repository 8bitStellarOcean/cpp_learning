#include<bits/stdc++.h>
using namespace std;
int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<vector<int>> g(n);
        vector<int> in(n); //入度
        for(auto& a:edges){
            if(a[0]==a[1]){//自环
                return -1;
            }
            g[a[0]].push_back(a[1]);
            in[a[1]]++;
        }
        //输出邻接表
        for(int i=0;i<n;i++){
            cout<<i<<": ";
            for(auto& b:g[i]){
                cout<<b<<" ";
            }
            cout<<endl;
        }
        queue<int> q;
        for(int i=0;i<in.size();i++){
            if(in[i]==0){
                q.push(i);
                cout<<i<<endl;
            }
        }
        vector<int> vis(n,0);//0:未访问 1:访问中 2:访问结束
        int result=0;
        vector<int> ans(26,0);
        auto dfs=[&](auto& self,int x)->bool{
            if(vis[x]==1)return false;
            bool val=true;
            if(vis[x]==0){
                vis[x]=1;
                ans[colors[x]-'a']++;
                for(auto& a:ans){
                    result=max(result,a);
                }
                for(auto& a:g[x]){
                    if(vis[a]==2)continue;
                    val=self(self,a);
                }
                vis[x]=0;
                ans[colors[x]-'a']--;
            }
            return val;
        };
        while(!q.empty()){
            int x=q.front();
            q.pop();
            vis=vector<int>(n,0);
            int val=dfs(dfs,x);
            if(!val)return -1;
        }
        return result;
    }
int main()
{   
    string colors="bbbhb";
    vector<vector<int>> edges={{0,2},{3,0},{1,3},{4,1}};
    cout<<largestPathValue(colors,edges)<<endl;
    return 0;
}