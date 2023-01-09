class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map< pair<int,int> ,int> mp;
        for(auto v : rectangles )
        {
            mp[{v[0],v[1]}]++;
            mp[{v[2],v[3]}]++;
            mp[{v[2],v[1]}]--;
            mp[{v[0],v[3]}]--;
        }
        int ans=0;
        for(auto i:mp)
        {
            if(abs(i.second)==1)ans++;
            else if(i.second)return false;
           
        }
        return ans==4;
    }
};
