#include <bits/stdc++.h>
using namespace std;
vector<string> divideString(string s, int k, char fill)
{
    int n = s.size();
    int num = 0;
    int mx = 0;
    if (n % k)
        mx = n / k + 1;
    else
        mx = n / k;
    vector<string> result;
    for (int i = 0; i < mx; i++)
    {
        string str="";
        for (int j = 0; j < k; j++)
        {
            int cur = i * k + j;
            if (cur < n)
                str.push_back(s[cur]);
            else
                str.push_back(fill);
        }
        //cout << str << endl;
        result.push_back(str);
    }
    return result;
}
int main()
{
    string s = "abcdefghi";
    int k = 3;
    char fill = 'x';
    vector<string> result = divideString(s, k, fill);
    for (string str : result)
        cout << str << endl;
    return 0;
}