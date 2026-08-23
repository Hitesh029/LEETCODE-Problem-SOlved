class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();

        int write = 0;
        int read = 0;

        while(read < n)
        {
            char curr = chars[read];
            int count = 0;

            while(read < n && chars[read] == curr)
            {
                count++;
                read++;
            }

            chars[write++] = curr;

            if(count > 1)
            {
                string freq = to_string(count);

                for(char ch : freq)
                {
                    chars[write++] = ch;
                }
            }
        }

        return write;
    }
};