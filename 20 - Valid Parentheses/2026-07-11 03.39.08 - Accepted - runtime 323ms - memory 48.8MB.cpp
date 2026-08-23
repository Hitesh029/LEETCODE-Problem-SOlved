class Solution {
public:
    bool isValid(string s) {

        while (true) {

            string temp = s;

            size_t pos;

            pos = s.find("()");
            if (pos != string::npos)
                s.erase(pos, 2);

            pos = s.find("[]");
            if (pos != string::npos)
                s.erase(pos, 2);

            pos = s.find("{}");
            if (pos != string::npos)
                s.erase(pos, 2);

            if (temp == s)
                break;
        }

        return s.empty();
    }
};