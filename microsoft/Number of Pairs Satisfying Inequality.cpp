class Solution {
public:
      long long cnt(vector <int> & v, int x, int m, int y,int d)
      {
          int l = x, r = m + 1;
          long long cnt1=0;
        while(l <= m && r <= y)
        {
            if(v[l]<=(v[r]+d)) { 
                cnt1 += (y - r+1);
                l++;
            }
            else     
            {
                r++;
            }
        }
         
        sort( v.begin() + x , v.begin() +y +1);
        return cnt1;
      }
    long long merge(vector<int>& v, int x, int y,int d)
    {
        if(x==y)return 0;
        int m=(x+y)/2;
        long cnt1=merge(v,x,m,d);
        long long cnt2=merge(v,m+1,y,d);
        return cnt1 + cnt2 + cnt(v,x,m,y,d);
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector <int> v(nums1.size());
        for(int i=0;i<nums2.size();i++)v[i]=nums1[i]-nums2[i];
       long long cnt=merge(v,0,nums1.size()-1,diff);
        return cnt;
    }
};
