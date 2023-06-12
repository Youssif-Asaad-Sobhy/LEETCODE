class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        string s;
        for(int i=0;i<nums.size();i++)
        {
            s=to_string(nums[i]);
            int oi=i;
            while(i+1<nums.size()&&nums[i]+1==nums[i+1])
            {
                i++;
            }
            if(oi!=i)
                s+="->",s+=to_string(nums[i]);
            ans.push_back(s);
        }
        return ans;
    }
};