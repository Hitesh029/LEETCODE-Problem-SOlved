class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>r;
        queue<int>d;

        int n=senate.size();
        int i = 0;

        for(char x: senate){
              if(x=='R'){
                 r.push(i);
              }
              else{
                 d.push(i); 
              }
              i++;
 

        }
        while(!r.empty()&& !d.empty()){
            int ra=r.front();
            r.pop();
            int di=d.front();
            d.pop();


            if(ra<di){
                r.push(ra+n);

            }
            else{
                d.push(di+n);
            }
        }
       return r.empty()? "Dire":"Radiant";      
    }
};