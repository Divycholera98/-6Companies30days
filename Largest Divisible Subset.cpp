class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
      int n=nums.size();
      vector <int> ans,dp(n,1);
      sort(nums.begin(), nums.end());
      for(int i=1;i<n;i++)
      {
          for(int j=0;j<i;j++)
          {
              if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1)
              {
                  dp[i]=dp[j]+1;
              }
          }
      }
      int x=*max_element(dp.begin(),dp.end()),y=-1;
      for(int i=n-1;i>=0;i--)
      {
         if(dp[i]==x && (y==-1 || y%nums[i]==0))
         {
             ans.push_back(nums[i]);
            x--;
            y=nums[i];
         }
      }
      return ans;
    }
};
