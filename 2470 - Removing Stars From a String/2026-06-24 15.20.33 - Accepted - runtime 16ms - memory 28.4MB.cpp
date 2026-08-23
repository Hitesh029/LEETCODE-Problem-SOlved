class Solution {
public:
    string removeStars(string s) {
        /*stack<char> st;
        for(char ch: s){
            if(ch=='*'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }

        string ans="";

        while(!st.empty()){
            ans+=st.top();
            st.pop();

        }
        reverse(ans.begin(), ans.end());*/

        string ans="";

        for(char ch: s)
        {
            if(ch=='*')
            {
                ans.pop_back();

            }
            else {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};