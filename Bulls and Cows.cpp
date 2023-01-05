class Solution {
public:
    string getHint(string secret, string guess) {
        int n=guess.size();
        int bull=0,cow=0;
        vector<int> v(n,1) , v1(n,1) ;
        for(int i=0;i<n;i++)
        {
            bull+=(guess[i]==secret[i]);
            v[i]-=(guess[i]==secret[i]);
            v1[i]=v[i];
        }
        for(int i=0;i<n;i++)
        {
           if(v[i])
           {
              for(int j=0;j<n;j++)
            {
                if(guess[i]==secret[j]  && v1[j])
                {
                    v1[j]=0;
                    cow++;
                    break;
                }
            }
           }
            
            
        }
        return to_string(bull)+"A"+to_string(cow)+"B";
    }
};

