class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<char>::iterator it;
        it=upper_bound(letters.begin(),letters.end(),target);
        return it==letters.end()?letters[0]:*it;
    }
};