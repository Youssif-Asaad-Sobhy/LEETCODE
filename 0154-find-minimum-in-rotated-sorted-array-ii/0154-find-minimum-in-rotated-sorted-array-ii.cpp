class Solution {
public:
    int findMin(vector<int>& nums) {
        int mn=5005;
        for(auto it:nums)mn=min(mn,it);
        return mn;
    }
};