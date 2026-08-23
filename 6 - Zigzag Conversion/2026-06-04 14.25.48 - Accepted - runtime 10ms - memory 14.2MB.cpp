class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;

        vector<string> rows(numRows);
        int currentRow=0;
        bool godown=false;

        for(char ch:s){
            rows[currentRow]+=ch;
            if(currentRow==0 ||currentRow==numRows-1)
            {
                godown=!godown;
            }
            currentRow+=godown?1:-1;
        }
        string ans ="";

        for(string row :rows){
            ans+=row;
        }
        return ans;

        
    }
};