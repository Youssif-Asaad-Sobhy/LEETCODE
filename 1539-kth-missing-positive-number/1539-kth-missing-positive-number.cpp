class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int j=0,cnt=0;
       for(int i=1;;i++)
       {
           if(j<arr.size()&&arr[j]==i){j++;continue;}
           cnt++;
           if(cnt==k)return i;
       }
    }
};