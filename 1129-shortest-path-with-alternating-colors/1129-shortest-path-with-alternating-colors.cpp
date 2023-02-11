class Solution {
public:
    int x;
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int>ans;
        vector<vector<int>>adjr(n),adjb(n);
        for(auto it:redEdges)adjr[it[0]].push_back(it[1]);
        for(auto it:blueEdges)adjb[it[0]].push_back(it[1]);
        for(int i=0;i<n;i++)
        {
            vector<vector<int>>vis(n,vector<int>(2,1000));
            x=i;
            int cnt=dfs(0,0,0,adjr,adjb,vis);
            vis=vector<vector<int>>(n,vector<int>(2,1000));
            cnt=min(cnt,dfs(0,1,0,adjr,adjb,vis));
            ans.push_back(cnt==1000?-1:cnt);
        }
        return ans;
    }
    int dfs(int i,bool state,int depth,vector<vector<int>>&adjr,vector<vector<int>>&adjb,vector<vector<int>>&vis)
    {
        if(vis[i][state]<depth)return 1000;
        if(i==x)return 0;
        vis[i][state]=depth;
        int cnt=1000;
        for(auto it:(state?adjr[i]:adjb[i]))
        {
            if(vis[it][!state]>depth+1)
            {
                cnt=min(1+dfs(it,!state,depth+1,adjr,adjb,vis),cnt);
            }
        }
        return cnt;
    }
};