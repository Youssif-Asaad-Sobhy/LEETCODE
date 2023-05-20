class Solution {
public:
    vector<int>vis;
    bool dfs(int node,int color,vector<vector<int>>& graph)
    {
        if(vis[node])return vis[node]==color;
        vis[node]=color;
        bool tr=1;
        for(auto it:graph[node])
        {
            tr&=dfs(it,(color==1?2:1),graph);
        }
        return tr;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vis=vector<int>(graph.size()+5);
        bool ans=1;
        for(int i=0;i<graph.size();i++)
        {
            if(!vis[i])
                ans&=dfs(i,1,graph);
        }
        return ans;
    }
};