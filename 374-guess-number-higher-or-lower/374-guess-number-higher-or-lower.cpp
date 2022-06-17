/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l=1,r=n,md,ans,x;
        while(r>=l)
        {
            md=l+(r-l)/2;
            x=guess(md);
            if(x==-1)r=md-1;
            else if(x==1)l=md+1;
            else break;
        }
        return md;
    }
};