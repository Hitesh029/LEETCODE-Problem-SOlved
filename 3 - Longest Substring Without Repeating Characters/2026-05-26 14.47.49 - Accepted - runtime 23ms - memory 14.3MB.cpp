class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> str;

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            while (str.count(s[right])) {
                str.erase(s[left]);
                left++;
            }

            str.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};