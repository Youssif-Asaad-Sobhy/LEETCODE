class Solution {
public:
    vector<bool>vis;
    vector<vector<int>>adj;
    void dfs(int node)
    {
        if(vis[node])return;
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])dfs(it);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vis=vector<bool>(n+1);
        adj=vector<vector<int>>(n+1);
        vector<int>mn(n+1,INT_MAX);
        for(auto it:roads)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            mn[it[0]]=min(mn[it[0]],it[2]);
            mn[it[1]]=min(mn[it[1]],it[2]);
        }
        dfs(1);
        int ans=INT_MAX,i=0;
        for(auto it:mn)if(vis[i++])ans=min(it,ans);
        return ans;
    }
};