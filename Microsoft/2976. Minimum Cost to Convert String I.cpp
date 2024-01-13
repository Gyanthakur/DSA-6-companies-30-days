/* https://leetcode.com/problems/minimum-cost-to-convert-string-i/ */

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<pair<int, int>> adj[27];
    long long dist[27];

    //dijsktra for finding the min 
    //distance between the two nodes
    bool bfs(int src, int dst, long long &cost)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({ 0,src });
        dist[src] = 0;

        while (!pq.empty())
        {
            int prevNode = pq.top().second;
            int prevDist = pq.top().first;

            pq.pop();

            if (prevNode == dst)
            {
                cost = dist[dst];
                return true;
            }

            for (auto it : adj[prevNode])
            {
                int currNode = it.first;
                int currDist = it.second;

                if (dist[currNode] > prevDist + currDist)
                {
                    dist[currNode] = prevDist + currDist;
                    pq.push({dist[currNode], currNode});
                }
            }
        }

        return false;;

    }
    
    long long hashFunc(int a, int b)
    {
        a+=1;
        b+=1;
        return (a*1000000+b*27);
    }
    
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long ans = 0;
        unordered_map<long long,long long> mp;
        mp.clear();
        
        for (int i = 0; i < changed.size(); i++)
        {
            adj[original[i] - 'a'].push_back({ (changed[i] - 'a'),cost[i] });
        }

        for (int i = 0; i < source.length(); i++)
        {
            int src = source[i] - 'a';
            int dst = target[i] - 'a';

            if (src == dst) {
                continue;
            }
            
            long long sum = 0;
            int hash = hashFunc(src,dst);

            //to check if we have already found the min distance
            //between these 2 elements then just return it otherwise
            //calculate the distance between them, this would help to reduce the 
            //time complexity
            if(mp[hash]!=0)
            {
                ans+=mp[hash];
                continue;
            }
            
            for (int i = 0; i < 27; i++)
            {
                dist[i] = INT_MAX;
            }

            bool poss = bfs(src, dst, sum);
            if (poss)
            {
                long long hash = hashFunc(src,dst);
                mp[hash] = sum;
                ans += sum;
            }
            else
            {
                return -1;
            }
        }
        return ans;

    }
};