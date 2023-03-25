class Solution {
public:
    vector<bool>vis;
    vector<vector<int>>adj;
    int dfs(int node)
    {
        if(vis[node])return 0;
        vis[node]=1;
        int cnt=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                cnt+=dfs(it);
            }
        }
        return cnt;
    }    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vis=vector<bool>(n+1);
        adj=vector<vector<int>>(n+1);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<long long >pre;
        pre.push_back(0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                pre.push_back(pre.back()+dfs(i));
            }
        }
        long long ans=0;
        for(int i=1;i<pre.size();i++)
        {
            ans+=(pre.back()-pre[i])*(pre[i]-pre[i-1]);
        }
        return ans;
    }
};