class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector <long long> dp(n,0);
        long long ans=0;
        int M = 1e9 + 7;
      
        dp[0] = 1;
        for(int i=0;i<n;i++)
        {
            for(int j=delay ; j<forget && i+j<n;j++)
            {
                dp[i+j]= (dp[i+j]+dp[i])%M;
            }
             ans = (ans + dp[i]) % M;
             if(i>=forget)
             {
                 ans=(ans-dp[i-forget]+M)%M;
             }
        }
        return ans;
    }
};
