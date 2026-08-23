class Solution {
public:

    string substring(string &s , int left, int right){
        while(left>=0 && right<s.size() && s[left]==s[right])
     {
        left--;
      
      right++;
     }
    return s.substr(left+1,right-left-1);
    }
    string longestPalindrome(string s) {
        string ans="";

        for(int i=0; i<s.size(); i++){
            string odd=substring(s,i,i);

            if (odd.length()> ans.length())
               ans=odd;

            string even =substring(s,i,i+1);

            if(even.length()> ans.length())
            ans=even;
        }

        return ans;
    }
};