class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0,n=nums.size();
        int ans=0,x=0;
        for( int i=0;i<n;i++)sum+=nums[i],x+=i*nums[i];
        ans=x;
        for(int i=n-1;i>=0;i--)
        {
            x+=sum-nums[i]*(n);
            ans=max(ans,x);
        }
        return ans;
    }
};
