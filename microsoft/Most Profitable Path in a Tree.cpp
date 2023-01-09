class Solution {
public:
    vector<vector<int>>g;
    vector<int>par,dis;
     void dfs(int x,int p = 0,int d = 0){
        dis[x] = d;
        par[x] = p;
        for(int v: g[x]){
            if(v==p)continue;
            dfs(v,x,d+1);
        }
    }
    int dfs2(int x,vector<int>& a,int p= 0){
        int ret = a[x];
        int m =INT_MIN;
        for(int v:g[x]){
            if(v!=p){
                m= max(m,dfs2(v,a,x));
            }
        }
		//if the node is leaf we just return its amount
        if(m==INT_MIN)return ret;
        else return ret+m;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        g.resize(n,vector<int>());
        for ( auto i : edges)
        {
            g[i[0]].push_back(i[1]); 
            g[i[1]].push_back(i[0]);
        }
        par.resize(n);
        dis.resize(n);
        dfs(0);
        int x = bob;
        int y = 0;
        while(x!=0){
            if(dis[x]>y){
                amount[x] = 0;
            }else if(dis[x]==y){
                amount[x]/=2;
            }
            x = par[x];
            y++;
        }
        return dfs2(0,amount);
    }
};
