class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int x=numsDivide[0],ans=INT_MAX;
        for(int i=0;i<numsDivide.size();i++)
        {
            x=__gcd(numsDivide[i],x);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(x%nums[i]==0)ans=min(ans,nums[i]);
        }
         if(ans==INT_MAX)return -1;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<ans)cnt++;
        }
        return cnt;
    }
};
