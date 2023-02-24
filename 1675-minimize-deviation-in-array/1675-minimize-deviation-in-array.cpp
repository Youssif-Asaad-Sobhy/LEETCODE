class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n=nums.size(),mx=0,mn=INT_MAX;
        priority_queue<int>pq;
        for(auto &it:nums)
        {
            if(it%2==1)pq.push(it*2),it*=2;
            else pq.push(it);
            mx=max(mx,it);
            mn=min(mn,it);
        }
        int ans=mx-mn;
        while(pq.top()%2==0)
        {
            int tmp=pq.top();
            pq.pop();
            ans=min(ans,tmp-mn);
            tmp/=2;
            pq.push(tmp);
            mn=min(mn,tmp);
        }
        return min(ans,pq.top()-mn);
    }
};