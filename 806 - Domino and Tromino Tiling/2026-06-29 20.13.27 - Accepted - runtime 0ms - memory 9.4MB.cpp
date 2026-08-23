class Solution {
public:
    int numTilings(int n) {

        const int MOD = 1e9+7;

        vector<long long> full(n+2);
        vector<long long> partial(n+2);

        full[0]=1;
        full[1]=1;
        full[2]=2;

        partial[2]=1;

        for(int i=3;i<=n;i++)
        {
            full[i]=(full[i-1]+full[i-2]
                    +2*partial[i-1])%MOD;

            partial[i]=(partial[i-1]
                       +full[i-2])%MOD;
        }

        return full[n];
    }
};