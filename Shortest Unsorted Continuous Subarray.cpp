class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector <int> v(nums.begin(),nums.end());
        sort(v.begin(),v.end());
        int x=0,y=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]!=nums[i]){x=i;break;}
        }
        for(int i=n-1;i>=0;i--)
        {
            if(v[i]!=nums[i]){y=i;break;}
        }
        return y==x?0:y-x+1;
    }
};

