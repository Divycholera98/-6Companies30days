class Solution {
public:
    set<set<int>> ans;
    void func(int x,set <int> st,int n,int k,int sum)
    {
        if(sum==n && st.size()==k)
        {
            
            ans.insert(st);
        }
        if(sum>n || st.size()>k || x==10 )return;
        func(x+1,st,n,k,sum);
        st.insert(x);
        func(x+1,st,n,k,sum+x);

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        set <int> st;
        for(int i=1;i<=9;i++)
        {
          func(i,st,n,k,0);   
        }
        vector<vector <int> > v;
        for(auto i : ans)v.push_back(vector <int> (i.begin(),i.end()) );
        return v;
    }
};
