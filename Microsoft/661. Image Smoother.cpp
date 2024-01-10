/* https://leetcode.com/problems/image-smoother/description/ */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        int *x = new int[]{-1, -1, -1, 0, 0, 0, 1, 1, 1};
        int *y = new int[]{-1, 0, 1, -1, 0, 1, -1, 0, 1};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int sum = 0, cnt = 0;
                for (int k = 0; k <= 8; k++)
                {
                    int xi = i + x[k];
                    int yi = j + y[k];
                    if (xi >= 0 && xi < n && yi >= 0 && yi < m)
                    {
                        sum += img[xi][yi];
                        cnt++;
                    }
                }
                ans[i][j] = sum / cnt;
            }
        }
        return ans;
    }
};