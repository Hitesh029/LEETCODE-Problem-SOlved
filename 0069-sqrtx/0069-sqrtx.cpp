class Solution {
public:
    int mySqrt(int x) {
        if(x<2)
            return x;
        for(long long i=1; i<=x; i++){
           if(i*i>x)
              return i-1;    
        }

        return x;
    }
};