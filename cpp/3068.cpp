#include <bits/stdc++.h>
using namespace std;
long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
{
    int n = nums.size();
    long long res = 0;
    for (auto &a : nums)
    {
        res += a;
    }
    vector<int> diff(n, 0);
    for (int i = 0; i < n; i++)
    {
        diff[i] = (nums[i] ^ k) - nums[i];
    }
    sort(diff.begin(), diff.end(), greater<int>());
    for (int i = 0; i < n; i++)
    {
        cout << diff[i] << " ";
    }
    cout << endl;
    for (int i = 1; i < n; i += 2)
    {
        if ((diff[i] + diff[i - 1]) <= 0)
            break;
        res += (diff[i] + diff[i - 1]);
    }
    return res;
}
int main()
{
    vector<int> nums = {1, 2, 1};
    // sort(v.begin(),v.end(),greater<int>());
    // for(auto i:v)
    // {
    //     cout<<i<<" ";
    // }
    cout << endl;
    vector<vector<int>> edges = {{0, 1}, {0, 2}};
    long long res = maximumValueSum(nums, 3, edges);
    cout << res << endl;
    return 0;
}