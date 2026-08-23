class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
                vector<string> ans;
        int n = words.size();
        int i = 0;
        while(i < n){
            int j = i;
            int total = 0;
            while(j < n){
                if(total + words[j].size() + (j - i) > maxWidth)
                    break;
                total += words[j].size();
                j++;
            }
            int spaces = maxWidth - total;
            int count = j - i;
            string line = "";

            if(j == n || count == 1){
                for(int k = i; k < j; k++){
                    line += words[k];
                    if(k != j - 1)
                        line += " ";
                }
                line += string(maxWidth - line.size(), ' ');
            }
            else{
                int gap = spaces / (count - 1);
                int extra = spaces % (count - 1);

                for(int k = i; k < j; k++){
                    line += words[k];
                    if(k != j - 1){
                        line += string(gap, ' ');
                        if(extra > 0){
                            line += " ";
                            extra--;
                        }
                    }
                }
            }
            ans.push_back(line);
            i = j;
        }
         return ans;
    }
};