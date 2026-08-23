class Solution {
public:
    int minFlips(int a, int b, int c) {

        int ans = 0;

        for(int i = 0; i < 32; i++)
        {
            int x = (a >> i) & 1;
            int y = (b >> i) & 1;
            int z = (c >> i) & 1;

            if((x | y) != z)
            {
                if(z == 1)
                    ans++;
                else
                    ans += x + y;
            }
        }

        return ans;
    }
};