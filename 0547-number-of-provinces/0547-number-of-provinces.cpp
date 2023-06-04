class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>vis(n+1);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans++;
                queue<int>q;
                q.push(i);
                vis[i]=1;
                while(q.size())
                {
                    int node=q.front();
                    q.pop();
                    for(int j=0;j<n;j++)
                    {
                        if(!vis[j]&&isConnected[node][j])
                        {
                            vis[j]=1;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return ans;
    }
};