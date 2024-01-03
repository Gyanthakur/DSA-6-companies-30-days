/*https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/ */


#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<set>
using namespace std;
// #define int long long
long long  t;
void solution()
{

}
signed main()
{
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
cin>>t;
while(t--)
{
solution();
cout<<endl;
}
return 0;
}


class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        long d=(divisor1*divisor2)/__gcd(divisor1,divisor2); //        long d=lcm((long)divisor1, divisor2);
        int lo=1, hi=INT_MAX, n, cnt, a, b, c;
        while(lo<hi) {
            n=lo+(hi-lo)/2;
            c=n/d;
			a=n/divisor1-c;
            b=n/divisor2-c;
            cnt=min(a, uniqueCnt2)+min(b, uniqueCnt1)-a-b-c+n;
            if(cnt<uniqueCnt1+uniqueCnt2) {
                lo=n+1;
            } else {
                hi=n;
            }
        }
        return lo;
    }
};