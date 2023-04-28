class Solution {
public:
    bool similar(string s1,string s2)
    {
        int cnt=0;
        for(int i=0;i<s1.size();i++)
            cnt+=s1[i]!=s2[i];
        return cnt<=2;
    }
    void DFS(int i,vector<bool>&vis,vector<vector<int>>&adj)
    {
        if(vis[i])return;
        vis[i]=1;
        for(auto it:adj[i])
            if(!vis[it])
                DFS(it,vis,adj);
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(similar(strs[i],strs[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans=0;
        vector<bool>vis(n);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                ans++,DFS(i,vis,adj);
        }
        return ans;
    }
};