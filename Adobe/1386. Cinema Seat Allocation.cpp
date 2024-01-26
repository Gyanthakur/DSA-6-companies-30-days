/*  https://leetcode.com/problems/cinema-seat-allocation/description/ */


#include<bits/stdc++.h>
using namespace std;
class Solution
{

    int fun(int start, int end)
    {
        // there r only four possible sitting arrarngments

        if (2 >= start && 9 <= (end)) // 2-four people from 2->9
            return 2;
        else if (2 >= start && 5 <= (end))
            return 1; // 1-four from 2-5
        else if (6 >= start && 9 <= (end))
            return 1; // 1-four from 6-9
        else if (4 >= start && 7 <= (end))
            return 1; // 1-four from 4-7

        return 0; // or else cant;
    }

public:
    int maxNumberOfFamilies(int n, vector<vector<int>> &a)
    {

        int ans = 0;

        sort(a.begin(), a.end());

        int present = a[0][0];
        int last = 1;

        set<int> st; // this set is for
        // assume n=3, means 3 rows, but only 3rd row is reserved, so row-1 will contribute 2 four-seat + row-2 will contribute 2 four-seat
        // i hav added the remaining at last
        st.insert(present);

        for (int i = 0; i < a.size(); i++)
        {
            if (present == a[i][0])
            {
                ans += fun(last, (a[i][1] - 1));

                last = a[i][1] + 1;
            }
            else
            {
                ans += fun(last, 10);

                ans += fun(1, a[i][1] - 1);

                st.insert(a[i][0]);

                present = a[i][0];
                last = a[i][1] + 1;
            }
        }

        ans += fun(last, 10);

        if (st.size() != n)
            ans += (2 * (n - st.size()));

        return ans;
    }
};