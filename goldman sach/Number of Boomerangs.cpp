class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& p) {
        int ans=0;
        for(int i=0 ;i<p.size();i++)
        {
            map<int,int> mp;
            int x=p[i][0];
            int y=p[i][1];
        for(int j=0 ;j<p.size();j++)
        {
            int x1=p[j][0];
            int y1=p[j][1];
            mp[(x-x1)*(x-x1) + (y-y1)*(y-y1)]++;
        }
            for(auto a : mp )
            {
                ans+=(a.second)*(a.second-1);
            }
        }
        return ans;
    }
};
