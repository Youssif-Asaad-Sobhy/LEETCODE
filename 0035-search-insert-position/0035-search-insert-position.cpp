class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,md,ans;
        while(l<=r)
        {
            md=(l+r)/2;
            if(nums[md]<target)
                l=md+1,ans=md;
            else if(nums[md]>target)
                r=md-1,ans=md;
            else return md;
        }
        return l;
    }
};