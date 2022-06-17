class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx=-1;
        if(binary_search(nums.begin(),nums.end(),target))
            idx=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        return idx;
    }
};