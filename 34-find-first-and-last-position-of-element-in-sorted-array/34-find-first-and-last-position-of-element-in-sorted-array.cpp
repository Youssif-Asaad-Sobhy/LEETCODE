class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int b,e;
        b=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        e=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        vector<int>v={-1,-1},vv={b,e-1};
        return (b==e)?v:vv;
    }
};