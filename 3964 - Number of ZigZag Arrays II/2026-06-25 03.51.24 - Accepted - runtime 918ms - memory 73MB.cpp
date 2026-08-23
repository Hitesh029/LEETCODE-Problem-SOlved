
class Solution {
    const int MOD = 1e9 + 7;
    typedef vector<vector<long long>> Matrix;
 
    Matrix multiply(const Matrix& A, const Matrix& B) {
        int sz = A.size();
        Matrix C(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; i++)
            for (int k = 0; k < sz; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < sz; j++)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        return C;
    }
 
    Matrix matpow(Matrix M, long long p) {
        int sz = M.size();
        Matrix result(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; i++) result[i][i] = 1;
        while (p > 0) {
            if (p & 1) result = multiply(result, M);
            M = multiply(M, M);
            p >>= 1;
        }
        return result;
    }
 
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int sz = 2 * m;
 
        if (n == 1) return m % MOD;
 
        Matrix T(sz, vector<long long>(sz, 0));
        for (int v = 0; v < m; v++) {
            for (int w = 0; w < v; w++)
                T[v][w + m] = 1;
            for (int w = v + 1; w < m; w++)
                T[v + m][w] = 1;
        }
 
        vector<long long> init(sz, 0);
        for (int a = 0; a < m; a++) {
            for (int b = 0; b < m; b++) {
                if (a == b) continue;
                if (b > a) init[b]++;
                else init[b + m]++;
            }
        }
        for (auto& x : init) x %= MOD;
 
        if (n == 2) {
            long long ans = 0;
            for (auto x : init) ans = (ans + x) % MOD;
            return ans;
        }
 
        Matrix Tp = matpow(T, n - 2);
 
        vector<long long> final_state(sz, 0);
        for (int to = 0; to < sz; to++)
            for (int from = 0; from < sz; from++)
                final_state[to] = (final_state[to] + Tp[from][to] * init[from]) % MOD;
 
        long long ans = 0;
        for (auto x : final_state) ans = (ans + x) % MOD;
        return ans;
    }
};
 