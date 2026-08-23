class Solution {
public:
    bool isValid(string s) {
        while (true){
            string temp =s;
            s.erase(s.find("()"),2);
            s.erase(s.find("()"),2);
        }
    }
};