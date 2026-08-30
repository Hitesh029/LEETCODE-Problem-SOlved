class Solution {
public:

    bool valid(char c) {

        if(c >= 'a' && c <= 'z')
            return true;

        if(c >= 'A' && c <= 'Z')
            return true;

        if(c >= '0' && c <= '9')
            return true;

        return false;
    }

    char lower(char c) {

        if(c >= 'A' && c <= 'Z')
            return c - 'A' + 'a';

        return c;
    }

    bool isPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        while(left < right) {

            while(left < right && !valid(s[left]))
                left++;

            while(left < right && !valid(s[right]))
                right--;

            if(lower(s[left]) != lower(s[right]))
                return false;

            left++;
            right--;
        }

        return true;
    }
};