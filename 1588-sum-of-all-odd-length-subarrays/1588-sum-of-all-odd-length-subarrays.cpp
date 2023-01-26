class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int>v(arr.size()+1);
        for(int i=0;i<arr.size();i++)
        {
            v[i+1]=v[i]+arr[i];
        }
        int ans=0;
        for(int i=1;i<=arr.size();i+=2)
        {
            for(int j=0;j+i<v.size();j++)
            {
                ans+=(v[j+i]-v[j]);
            }
        }
        return ans;
    }
};