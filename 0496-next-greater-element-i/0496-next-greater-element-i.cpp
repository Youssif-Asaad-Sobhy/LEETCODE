class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(int i=0;i<nums1.size();i++)
        {
            int a=-1;
            bool tr=0;
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])tr=1;
                else if(tr&&nums2[j]>nums1[i])
                {
                    a=nums2[j];
                    break;
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};