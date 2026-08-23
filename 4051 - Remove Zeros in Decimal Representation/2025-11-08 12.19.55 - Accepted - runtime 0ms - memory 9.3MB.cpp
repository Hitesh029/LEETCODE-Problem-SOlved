class Solution {
public:
    long long removeZeros(long long n) {
         long long x =n;
    long long ans=0;
    int j=0;
    while(x>0){
        int temp=x%10;
        if (temp!=0){
        ans=temp * pow(10 , j)+ans;
        j++;
        }
        x=x/10;
    
    }
    return ans;
    }
};

