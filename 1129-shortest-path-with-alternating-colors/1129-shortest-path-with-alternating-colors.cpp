class Solution {
public:
    vector<vector<int>>adjr,adjb;
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int>ans;
        adjr=adjb=vector<vector<int>>(n);
        for(auto it:redEdges)adjr[it[0]].push_back(it[1]);
        for(auto it:blueEdges)adjb[it[0]].push_back(it[1]);
        for(int i=0;i<n;i++)
        {
            ans.push_back(bfs(i));
        }
        return ans;
    }
    int bfs(int ed)
    {
        queue<pair<int,bool>>q;
        q.push({0,0});
        q.push({0,1});
        vector<vector<int>>dist(adjr.size(),vector<int>(2,1000));
        dist[0][0]=0;
        dist[0][1]=0;
        while(q.size())
        {
            int node=q.front().first;
            int state=q.front().second;
            int dis=dist[node][state];
            q.pop();
            if(node==ed)return dis;
            for(auto child:(state?adjr[node]:adjb[node]))
            {
                if(dist[child][!state]>dis+1)
                {
                    dist[child][!state]=dis+1;
                    q.push({child,!state});
                }
            }
        }
        return -1;
    }
};