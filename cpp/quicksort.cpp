#include <bits/stdc++.h>
using namespace std;
void quicksort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;
    int pivot = nums[left];
    int lt = left, gt = right;
    for (int i = left + 1; i <= gt; i++)
    {
        if (nums[i] < pivot)
        {
            swap(nums[lt++], nums[i]);
        }
        else if(nums[i] > pivot)
        {
            swap(nums[i--], nums[gt--]);
        }
    }
    quicksort(nums, left, lt - 1);
    quicksort(nums, gt + 1, right);
}
int main()
{
    vector<int> nums = {7, 7, 7, 7, 7, 7, 2, 8, 5, 3, 0, 9, 7, 7, 7};
    quicksort(nums, 0, nums.size() - 1);
    for (auto i : nums)
        cout << i << " ";
    cout << endl;
    return 0;
}