class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        
        vector<bool>ans(n);
        
        int mx=0;
        
        for(auto it:candies)mx=max(mx,it);
        
        for(int i=0;i<n;i++)ans[i]=(candies[i]+extraCandies)>=mx;
        return ans;
    }
};