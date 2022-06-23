// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l=1,r=n,md;
        while(l<=r)
        {
            md=(l+r)/2;
            if(isBadVersion(md))r=md-1;
            else l=md+1;
        }
        return r+1;
    }
};