class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> str;

        int l = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            while (str.count(s[right])) {
                str.erase(s[l]);
                l++;
            }

            str.insert(s[right]);
            maxLen = max(maxLen, right - l + 1);
        }

        return maxLen;
    }
};