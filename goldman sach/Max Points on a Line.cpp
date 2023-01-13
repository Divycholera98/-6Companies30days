class Solution {
public:
    int maxPoints(vector<vector<int>>& v) {
        int cnt=0;
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            double x=v[i][0];
            double y=v[i][1];
            for(int j=i+1;j<n;j++)
            {
                double s= (y-v[j][1])/(x-v[j][0]);
                int z=0;
                for(int k=0;k<n;k++)
                {
                   if(i!=k)
                   {
                       if((y-v[k][1])/(x-v[k][0])==s)z++;
                   }
                }
                cnt=max(cnt,z);
            }
        }
        return cnt+1;
    }
};
