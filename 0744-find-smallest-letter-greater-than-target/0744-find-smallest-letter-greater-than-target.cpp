class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto a=upper_bound(letters.begin(),letters.end(),target);
        return a==letters.end()?letters[0]:*a;
    }
};