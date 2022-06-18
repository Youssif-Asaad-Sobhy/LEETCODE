class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=1,r=arr.size()-2,md;
        while(l<=r)
        {
            md=(l+r)/2;
            if(arr[md-1]<arr[md]&&arr[md+1]>arr[md])l=md+1;
            else if(arr[md-1]<arr[md]&&arr[md+1]<arr[md])return md;
            else r=md-1;
        }
        return 0;
    }
};