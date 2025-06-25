#include <bits/stdc++.h>
using namespace std;
void op(vector<string> ans)//输出调试用
{
    for (auto a : ans)
    {
        for (auto b : a)
        {
            cout << b << ' ';
        }
        cout << endl;
    }
    cout << endl;
}
void op2(vector<vector<bool>> v)//输出调试用
{
    for (auto a : v)
    {
        for (auto b : a)
        {
            cout << b << ' ';
        }
        cout << endl;
    }
    cout << endl;
}
int dir[4][2] = {0, 1, 1, -1, 1, 0, 1, 1};
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> result;
    vector<string> ans(n, string(n, '.'));
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    auto dfs = [&](int x, int y, int q, vector<vector<bool>> v,
                   auto &self)
    {
        v[x][y] = true;
        ans[x][y] = 'Q';
        //op(ans);
        if (q == 1)
        {
            result.push_back(ans);
            v[x][y] = false; // 提前回溯
            ans[x][y] = '.';
            return;
        }
        for (auto a : dir)
        {
            int nx = x + a[0], ny = y + a[1];
            while (!(nx < 0 || nx >= n || ny < 0 || ny >= n))
            {
                v[nx][ny] = true;
                nx = nx + a[0], ny = ny + a[1];
            }
        }
        //op2(v);
        //cout << x << ' ' << y << ' ' << q << endl;
        for (int i = x+1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                //cout << i << ' ' << j << endl;
                if (!v[i][j])
                    self(i, j, q - 1, v, self);
            }
        }
        // v[x][y] = false; // 回溯
        ans[x][y] = '.';
    };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans = vector<string>(n, string(n, '.'));
            dfs(i, j, n, vis, dfs);
        }
    }
    return result;
}

int main()
{
    auto result = solveNQueens(9);
    for (auto a : result)
    {
        op(a);
    }
    cout << "ok" << endl;

    return 0;
}