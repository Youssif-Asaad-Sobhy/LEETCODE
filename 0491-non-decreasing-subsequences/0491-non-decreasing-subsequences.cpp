class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>>st;
        vector<vector<int>>ans;
        for(int i=1;i<(1<<nums.size());i++)
        {
            if(!(i&(i-1)))
                continue;
            vector<int>temp;
            int prev=-105;
            for(int j=0;j<nums.size();j++)
            {
                int pow=1<<j;
                if(i&pow)
                {
                    if(nums[j]>=prev)
                    {
                        prev=nums[j];
                        temp.push_back(prev);
                    }
                    else goto cant;
                }
            }
            st.insert(temp);
            cant:continue;
        }
        for(auto it:st)ans.push_back(it);
        return ans;
    }
};