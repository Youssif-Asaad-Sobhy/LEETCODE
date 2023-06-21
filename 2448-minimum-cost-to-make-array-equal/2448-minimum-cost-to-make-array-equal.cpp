class Solution {
public:
    long long getCost(vector<int>& nums, vector<int>& cost,int cur)
    {
        long long ret=0,i=0;
        for(auto it:nums)ret+=1LL*abs(it-cur)*cost[i++];
        return ret;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans=LLONG_MAX;
        int l=0,r=1e6,md;
        while(l<=r)
        {
            md=(l+r)/2;
            long long cost1=getCost(nums,cost,md),cost2=getCost(nums,cost,md+1);
            if(cost1<=cost2)
                ans=cost1,r=md-1;
            else l=md+1;
        }
        return ans;
    }
};