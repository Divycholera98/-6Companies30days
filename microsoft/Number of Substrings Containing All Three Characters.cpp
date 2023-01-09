class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0,j=0,n=s.size();
        vector<int> v(3,0);
        for(int i=0;i<n;i++)
        {
            v[s[i]-'a']++;
            while(count(v.begin(),v.end(),0)==0)
            {
                ans+=n-i;
                v[s[j]-'a']--;
                j++;
            }
        }
        return ans;
    }
};
