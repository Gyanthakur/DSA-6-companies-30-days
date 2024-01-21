/* https://leetcode.com/problems/matrix-cells-in-distance-order/description/ */

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<vector<int>> allCellsDistOrder(int r, int c, int rCen, int cCen) {
		vector<vector<int>>ans;
		map<int,vector<vector<int>>>mp;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				int dis=abs(i-rCen)+abs(j-cCen);
				mp[dis].push_back({i,j});
			}
		}
		for(auto i:mp){
			for(auto j:i.second) ans.push_back(j);
		}
		return ans;
	}
};