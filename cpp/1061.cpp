#include<bits/stdc++.h>
using namespace std;
string smallestEquivalentString(string s1, string s2, string baseStr) {
    vector<vector<bool>> map(26,vector<bool>(26,false));
    for(int i=0;i<26;i++){
        map[i][i]=true;
    }
    int n=s1.size();
    for(int i=0;i<n;i++){
        char a=s1[i];
        char b=s2[i];

        map[a-'a'][b-'a']=true;
        map[b-'a'][a-'a']=true;
        for(int j=0;j<26;j++){
            map[a-'a'][j]=map[b-'a'][j]||map[a-'a'][j];
            map[b-'a'][j]=map[b-'a'][j]||map[a-'a'][j];
            map[j][a-'a']=map[j][a-'a']||map[j][b-'a'];
            map[j][b-'a']=map[j][a-'a']||map[j][b-'a'];
        }
    }
    for(auto& a:baseStr){
        for(int i=0;i<26;i++){
            if(map[a-'a'][i]){
                a=i+'a';
                break;
            }
        }
    }
    cout<<"  ";
    for(int i=0;i<26;i++){
        cout<<char(i+'a')<<" ";
    }cout<<endl;
    for(int i=0;i<26;i++){
        cout<<char(i+'a')<<" ";
        for(int j=0;j<26;j++){
            if(map[i][j]){
                cout<<"\033[33mo \033[0m";
            }else{
                cout<<"+ ";
            }
        }
        cout<<endl;
    }
    return baseStr;

}
int main()
{   
    string s1="gmerjboftfnqseogi";//"gmerjboftfnqseogigpdnlocmmhskigdtednfnjtlcrdpcjkbj"
    string s2="fnnafafhqkitbcdlk";//"fnnafafhqkitbcdlkpiloiienikjiikdfcafisejgeldprcmhd"
    string baseStr="ezrqfyguivmybqcsvibuvtajdvamcdjpmgcbvieegpyzdcypcx";//"ezrqfyguivmybqcsvibuvtajdvamcdjpmgcbvieegpyzdcypcx"
    cout<<smallestEquivalentString(s1,s2,baseStr)<<endl;
    return 0;

}