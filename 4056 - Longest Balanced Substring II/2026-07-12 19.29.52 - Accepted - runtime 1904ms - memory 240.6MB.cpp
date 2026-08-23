class Solution {
public:
    int cal1(string &s){
        if(s.empty())
           return 0;
        int ans=1;
        int count=1;
        for(int i=1; i<s.size(); i++){
            if(s[i]==s[i-1])
               count++;
            else
               count=1;
            ans=max(ans,count);      
        }
        return ans;
    }
    int cal2(string &s,char x, char y){
        unordered_map<int,int> mp;

        mp[0]=-1;
        int diff=0;
        int ans=0;
                for(int i=0;i<s.size();i++){

            if(s[i]==x)
                diff++;

            else if(s[i]==y)
                diff--;

            else{

                mp.clear();

                mp[0]=i;

                diff=0;

                continue;
            }

            if(mp.count(diff))
                ans=max(ans,i-mp[diff]);

            else
                mp[diff]=i;
        }

        return ans;
    }

    int cal3(string &s){

        map<pair<int,int>,int> mp;

        mp[{0,0}]=-1;

        int a=0,b=0,c=0;

        int ans=0;

        for(int i=0;i<s.size();i++){

            if(s[i]=='a') a++;
            else if(s[i]=='b') b++;
            else c++;

            pair<int,int> key={b-a,c-a};

            if(mp.count(key))
                ans=max(ans,i-mp[key]);

            else
                mp[key]=i;
        }

        return ans;
    }
 
    
    int longestBalanced(string s) {
        int ans=cal1(s);
        
        ans=max(ans,cal2(s,'a','b'));
        ans=max(ans,cal2(s,'a','c'));
        ans=max(ans,cal2(s,'b','c'));

        ans=max(ans,cal3(s));

        return ans;

    }
};