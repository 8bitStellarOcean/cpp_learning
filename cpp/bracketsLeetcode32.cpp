#include<bits/stdc++.h>
using namespace std;
int longestValidParentheses(string s) {
    stack<int> st;
    vector<vector<int>> ans;
    if(s.size()<=1)return 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push(i);
        }else if(!st.empty()){
            auto a=st.top();
            st.pop();
            ans.push_back({a,i});
        }
    }
    if(ans.size()==0)return 0;
    int result=ans[0][1]-ans[0][0]+1;
    for(int i=1;i<ans.size();i++){
        if(ans[i][0]==ans[i-1][1]+1){
            ans[i][0]=ans[i-1][0];
        }else if(ans[i][0]<ans[i-1][0]&&ans[i][1]>ans[i-1][1]){
            ans.erase(ans.begin()+i-1);
            if(i-2>=0)i=i-2;
            else i=0;
        }
        result=max(result,ans[i][1]-ans[i][0]+1);
    }
    for(auto a:ans){
        cout<<a[0]<<" "<<a[1]<<endl;
    }
    return result;
}
int main(){
    string s="()(())";
    int a=longestValidParentheses(s);
    cout<<a<<endl;
    return 0;
}