class Solution {
public:
  bool check(string s, string base)
    {
        int n = base.size();

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != base[i % n])
                return false;
        }

        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        
        int g=gcd(str1.size(),str2.size());
        string base=str1.substr(0,g);
       if(check(str1,base)&&check(str2,base)){
        return base;
       }
       return "";
        
    }
};