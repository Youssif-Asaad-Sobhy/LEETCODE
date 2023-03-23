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
    int makeConnected(int n, vector<vector<int>>& con) {
        if(con.size()<n-1)return -1;
        vis=vector<bool>(n+1);
        adj=vector<vector<int>>(n+1);
        for(auto it:con)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(i);
            }
        }
        return ans-1;
    }
};