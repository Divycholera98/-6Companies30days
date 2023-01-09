class Solution {
public:
    bool dfs(vector< vector<int> > &v,vector<int> &vis,int x){
        if(vis[x]==1)
            return true;
        if(vis[x]==0){
            vis[x]=1;
            for(auto edge : v[x]){
                if(dfs(v,vis,edge))
                    return true;
            }
        }
        vis[x] = 2;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) 
    {
        vector< vector<int> > v(n);
        for(auto edge : prerequisites)
            v[edge[1]].push_back(edge[0]);
        
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(dfs(v,vis,i))
                return false;
        }
        return true;

    }
};
