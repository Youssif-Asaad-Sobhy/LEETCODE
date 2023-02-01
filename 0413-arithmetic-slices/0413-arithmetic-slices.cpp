class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0,cnt;
        for(int i=2;i<nums.size();i++)
        {
            cnt=2;
            while(i<nums.size()&&nums[i-2]-nums[i-1]==nums[i-1]-nums[i])
            {
                cnt++;
                i++;
            }
            ans+=((cnt-2)*(cnt-1))/2;
        }
        return ans;
    }
};