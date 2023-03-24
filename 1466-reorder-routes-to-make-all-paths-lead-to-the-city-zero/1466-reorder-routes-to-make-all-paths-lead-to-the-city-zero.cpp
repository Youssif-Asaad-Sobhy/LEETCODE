class Solution {
public:
    vector<bool>vis;
    vector<vector<pair<int,int>>>adj;
    int dfs(int node)
    {
        if(vis[node])return 0;
        vis[node]=1;
        int cnt=0;
        for(auto it:adj[node])
        {
            if(!vis[it.first])
            {
                cnt+=dfs(it.first)+(it.second);
            }
        }
        return cnt;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vis=vector<bool>(n+1);
        adj=vector<vector<pair<int,int>>>(n+1);
        for(auto it:connections)
        {
            adj[it[0]].push_back({it[1],1});
            adj[it[1]].push_back({it[0],0});
        }
        return dfs(0);
    }
};