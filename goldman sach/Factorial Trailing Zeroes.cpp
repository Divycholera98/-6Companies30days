class Solution {
public:
    int trailingZeroes(int n) {
        int c1=0,c2=0;
        for(int i=1;i<=n;i++)
        {
            int x=i;
            while(x%2==0 && x)
            {
                x/=2;
                c1++;
            }
            x=i;
            while(x%5==0 && x)
            {
                x/=5;
                c2++;
            }
        }
        return min(c1,c2);
    }
};
