class Solution {
public:
    string convertToTitle(int columnNumber) {
         if(columnNumber == 0)
            return "";

        columnNumber--;

        return convertToTitle(columnNumber / 26)
             + char('A' + columnNumber % 26);
    
        
        
        
        
        
        
        
        /*string ans = "";

        while(columnNumber > 0) {
            columnNumber--;

            int rem = columnNumber % 26;
            ans += char('A' + rem);

            columnNumber /= 26;
        }

        reverse(ans.begin(), ans.end());

        return ans;*/


    }
};
