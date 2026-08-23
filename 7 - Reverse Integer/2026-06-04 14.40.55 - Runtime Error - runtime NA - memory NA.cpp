class Solution {
public:
    int reverse(int x) {
    int reverse=0;
    while(x!=0){
      int x1=  x%10;
      reverse=reverse*10+x1;
      x=x/10;
    
     }
       return reverse;
    }
};