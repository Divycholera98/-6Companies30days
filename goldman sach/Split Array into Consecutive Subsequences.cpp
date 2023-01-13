class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> mp,mp1;
        for(auto i : nums)mp[i]++;
        for(auto i : nums)
        {
            if(mp[i]==0)continue;
            if(mp1[i])
            {
                mp1[i]--;
                mp[i]--;
                mp1[i+1]++;
            }
            else if(mp[i] && mp[i+1] && mp[i+2])mp[i]--,mp[i+1]--,mp[i+2]--,mp1[i+3]++;
            else return false;
        }
        return true;
    }
};
