class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int lastfruit= -1;
        int secondlastfruit=-1; 

        int lastcount=0;
        int curr=0;
        int ans=0;
        for(int fruit: fruits){
            if(fruit==lastfruit|| fruit==secondlastfruit)
                 curr++;
            else
               curr=lastcount+1;
            if(fruit==lastfruit){
                lastcount++;
            }    
            else{
                lastcount=1;
                secondlastfruit=lastfruit;
                lastfruit=fruit;
            }    
            ans=max(ans,curr);
        }

       
        return ans;
    }
};