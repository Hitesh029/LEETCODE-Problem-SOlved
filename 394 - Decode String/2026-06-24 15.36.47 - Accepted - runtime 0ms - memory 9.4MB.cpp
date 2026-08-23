class Solution {
public:
    string decodeString(string s) {

        stack<int> numSt;
        stack<string> strSt;

        string curr = "";
        int num = 0;

        for(char ch : s)
        {
            if(isdigit(ch))
            {
                num = num * 10 + (ch - '0');
            }

            else if(ch == '[')
            {
                numSt.push(num);
                strSt.push(curr);

                num = 0;
                curr = "";
            }

            else if(ch == ']')
            {
                int k = numSt.top();
                numSt.pop();

                string prev = strSt.top();
                strSt.pop();

                string temp = "";

                for(int i=0; i<k; i++)
                {
                    temp += curr;
                }

                curr = prev + temp;
            }

            else
            {
                curr += ch;
            }
        }

        return curr;
    }
};