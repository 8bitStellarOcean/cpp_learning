#include<bits/stdc++.h>
using namespace std;
int flag=0;
void func(int k){
    int bitnum=32 - __builtin_clz(k-1);
    k-=pow(2,bitnum-1);
    if(k>0){
        flag++;
        cout<<k<<endl;
        func(k);
    }
}
int main()
{
    int k=10;
    func(k);
    cout<<(char)('a'+flag)<<endl;
    return 0;
}