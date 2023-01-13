class Solution {
public:
    vector<int> maximumBobPoints(int sum, vector<int>& a) {
        vector<int>v;
        int maxi=0;
        for(int i=0; i<(1<<12); i++){
            int n=sum, cnt=0;
            vector<int>temp(12, 0);
            for(int j=11; j>=0; j--){
                if(i&(1<<j)){
                    if(n>a[j]){
                        n-=(a[j]+1);
                        temp[j]=(a[j]+1);
                    }
                }
            }
            for(int j=0; j<12; j++){
                if(i&(1<<j)){
                    temp[j]+=n;
                    break;
                }
            }
            for(int j=0; j<12; j++){
                if(temp[j]>a[j]){cnt+=j;}
            }
            if(cnt>maxi){
                maxi=cnt;
                v=temp;
            }
        }
        return v;
    }
};
