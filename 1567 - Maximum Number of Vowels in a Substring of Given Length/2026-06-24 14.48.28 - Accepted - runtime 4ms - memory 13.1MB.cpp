class Solution {
public:

    bool vowel(char ch)
    {
        return ch=='a' || ch=='e' ||
               ch=='i' || ch=='o' ||
               ch=='u';
    }

    int maxVowels(string s, int k) {

        int count = 0;

        for(int i=0; i<k; i++)
        {
            if(vowel(s[i]))
                count++;
        }
                 
        int mx = count;

        for(int i=k; i<s.size(); i++)
        {
            if(vowel(s[i]))
                count++;

            if(vowel(s[i-k]))
                count--;

            mx = max(mx,count);
        }

        return mx;
    }
};