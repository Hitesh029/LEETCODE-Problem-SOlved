class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0)
            return false;

        int original = x;
        int rev = 0;

        while (x > 0) {
            int x1 = x % 10;
            if(rev > INT_MAX/10 ||
               rev < INT_MIN/10)
            {
                return 0;
            }
            rev = rev * 10 + x1;
            x = x / 10;
        }

        if (original == rev)
            return true;
        else
            return false;
    }
};