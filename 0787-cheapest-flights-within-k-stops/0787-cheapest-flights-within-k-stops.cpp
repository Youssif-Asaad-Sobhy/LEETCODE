class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //                 to price
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        int ans=-1;
        
        return dijkstra(src,dst,k,adj);
    }
    long long dijkstra(int s, int e,int k,vector<vector<pair<int,int>>>&adj) {
        priority_queue<pair<long long, pair<int,int>> > q;
        q.push({0, {0,s}});
        int ans=1e9;
        vector<vector<int>>vis(adj.size()+5,vector<int>(adj.size()+5,1e9));
        vis[s][0]=0;
        while (q.size()) {
            int dis = q.top().second.first;
            int cur = q.top().second.second;
            int d = -q.top().first;
            q.pop();
            if(dis>k+1)continue;
            if (cur == e)
            {
                ans=min((int)d,ans);
                continue;
            }
            for (int i = 0; i < adj[cur].size(); ++i) {
                int j = adj[cur][i].first;
                long long dd = d + adj[cur][i].second;
                if (vis[j][dis+1]>dd) {
                    vis[j][dis+1]=dd;
                    q.push({-dd, {(dis+1),j}});
                    }
                }
            }
        return ans==1e9?-1:ans;
    }
};