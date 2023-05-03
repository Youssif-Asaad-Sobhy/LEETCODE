class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>f1,f2;
        for(auto it:nums1)f1[it]++;
        for(auto it:nums2)f2[it]++;
        vector<vector<int>>ans(2);
        for(int i=-1000;i<1001;i++)
        {
            if(f1[i]&&!f2[i])ans[0].push_back(i);
            if(!f1[i]&&f2[i])ans[1].push_back(i);
        }
        return ans;
    }
};