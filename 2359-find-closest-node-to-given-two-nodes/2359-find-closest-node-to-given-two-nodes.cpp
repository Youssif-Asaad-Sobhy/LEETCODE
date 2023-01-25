class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int>dis1(edges.size()+1,edges.size()+5),dis2(edges.size()+1,edges.size()+5);
        solve(node1,dis1,edges);
        solve(node2,dis2,edges);
        int ans=-1,mn=edges.size();
        for(int i=0;i<edges.size();i++)
        {
            if(max(dis1[i],dis2[i])<mn)
            {
                mn=max(dis1[i],dis2[i]);
                ans=i;
            }
        }
        return ans;
    }
    void solve(int st,vector<int>&dis,vector<int>&edges)
    {
        queue<int>q;
        q.push(st);
        dis[st]=0;
        while(q.size())
        {
            st=q.front();
            q.pop();
            if(edges[st]!=-1&&dis[st]+1<dis[edges[st]])
            {
                q.push(edges[st]);
                dis[edges[st]]=dis[st]+1;
            }
        }
    }
};