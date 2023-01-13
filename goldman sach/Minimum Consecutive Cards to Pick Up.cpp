class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map <int,vector<int> > mp;
        for(int i=0;i<cards.size();i++)
        {
            mp[cards[i]].push_back(i);
        }   
        int ans=1e6;
        for(auto n : mp)
        {
            vector<int> v=n.second;
            for(int i=0;i<v.size()-1;i++)
            {
                ans=min(ans,v[i+1]-v[i]+1);
            }
        }
        return ans==1e6?-1:ans;
    }
};
