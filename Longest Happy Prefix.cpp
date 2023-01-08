class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector <int> v(n,0);
        int i=0;
       for(int j= 1;j<n;){
            if(s[i]==s[j]){
                v[j]=i+1;
                i++;
                j++;
            }
            else if(i){
                i=v[i-1];
            }
            else{
                j++;
            }
        }
        return s.substr(0,i);
    }
};
