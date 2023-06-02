class Solution {
public:
    vector<vector<int>>adj;
    vector<bool>vis;
    double dis(int x,int y,int x2,int y2)
    {
        return sqrt((1LL*x-x2)*(x-x2)+(1LL*y-y2)*(y-y2));
    }
    int dfs(int node)
    {
        vis[node]=1;
        int cnt=1;
        for(auto it:adj[node])
        { 
            if(!vis[it])
                cnt+=dfs(it);
        }
       
        return cnt;
    }
    int maximumDetonation(vector<vector<int>>& v) {
        int n=v.size();
        adj=vector<vector<int>>(n+5);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;
                if(dis(v[i][0],v[i][1],v[j][0],v[j][1])<=v[i][2])
                {
                    adj[i].push_back(j);
                }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++)
        {
            vis=vector<bool>(n+1);
            mx=max(mx,dfs(i));
        }
        
        return mx;
    }
};