class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        short n=candies.size();
        
        vector<bool>ans(n);
        
        short mx=0;
        
        for(auto it:candies)mx=max(mx,(short)it);
        
        for(int i=0;i<n;i++)ans[i]=(candies[i]+extraCandies)>=mx;
        return ans;
    }
};