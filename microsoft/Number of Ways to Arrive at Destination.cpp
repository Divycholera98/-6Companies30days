class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector< vector< pair<long long , long long > > > g(n+1);
        for(auto x : roads)
        {
            g[x[0]].push_back({x[1], x[2]});
            g[x[1]].push_back({x[0], x[2]});
        }
        long long M = 1e9 + 7;
        vector <long long> dp(n+1, 0);
        vector <long long> dist(n+1, 1e15);
        multiset< pair<long long , long long >> st;
         dist[0] = 0;
        dp[0] = 1;
        st.insert({0,0});
        while(st.size())
        {
            long long x = st.begin()->second;
            long long y = st.begin()->first;
            st.erase(st.begin());
             if(dist[x] < y) continue;

             for(auto i: g[x]) {
                long long x1 = i.first;
                long long y1 = i.second;
                if(y + y1 == dist[x1]) dp[x1] = (dp[x1] + dp[x])%M;
                
                if(y + y1 < dist[x1]) {
                    dp[x1] = dp[x]%M; 
                    dist[x1] = y + y1;
                    st.insert({dist[x1], x1});
                }
            }

        }
        return dp[n-1];
    }
};
