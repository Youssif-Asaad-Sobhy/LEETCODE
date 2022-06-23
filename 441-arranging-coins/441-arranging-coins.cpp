class Solution {
public:
    long long s(long long n){return n*(n+1)/2;}
    int arrangeCoins(int n) {
        long long l=1,r=n,md;
        while(l<=r)
        {
            md=(l+r)/2;
            if(s(md)<n)l=md+1;
            else if(s(md)==n)return md;
            else r=md-1;
        }
        return l-1;
    }
};