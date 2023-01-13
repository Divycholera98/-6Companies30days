class Solution {
public:
    int rev(int x)
    {
        int z=0;
        while(x)
        {
            z=z*10+x%10;
            x/=10;
        }
        return z;
    }
    int countNicePairs(vector<int>& v) {
        int n=v.size();
        map<int,int>mp;
        long long ans=0,M=1e9+7;
        for(int i=0;i<n;i++)
        {
            int x=v[i]-rev(v[i]);
            mp[x]++;
            ans=(ans+mp[x]-1)%M;
        }
        
        
        return ans;
    }
};
