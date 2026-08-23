 
class Solution {
    const int MOD = 1e9 + 7;
    typedef vector<vector<int>> Matrix;
 
    Matrix multiply(const Matrix& A, const Matrix& B) {
        int sz = A.size();
        Matrix C(sz, vector<int>(sz, 0));
        for (int i = 0; i < sz; i++)
            for (int k = 0; k < sz; k++) {
                if (!A[i][k]) continue;
                for (int j = 0; j < sz; j++)
                    C[i][j] = (C[i][j] + (long long)A[i][k] * B[k][j]) % MOD;
            }
        return C;
    }
 
    Matrix matpow(Matrix M, long long p) {
        int sz = M.size();
        Matrix R(sz, vector<int>(sz, 0));
        for (int i = 0; i < sz; i++) R[i][i] = 1;
        for (; p; p >>= 1) {
            if (p & 1) R = multiply(R, M);
            M = multiply(M, M);
        }
        return R;
    }
 
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1, M = m - 1;
        int sz = 2 * m;
 
        if (n == 1) return m % MOD;
 
        Matrix T(sz, vector<int>(sz, 0));
        for (int v = 0; v < m; v++) {
            for (int w = 0; w < v; w++)     T[v][w + m] = 1;
            for (int w = v + 1; w < m; w++) T[v + m][w] = 1;
        }
 
        vector<long long> init(sz, 0);
        for (int b = 0; b < m; b++) {
            init[b]     = b;
            init[b + m] = M - b;
        }
 
        if (n == 2) {
            long long ans = 0;
            for (auto x : init) ans = (ans + x) % MOD;
            return ans;
        }
 
        Matrix Tp = matpow(T, n - 2);
 
        long long ans = 0;
        for (int to = 0; to < sz; to++) {
            long long col = 0;
            for (int from = 0; from < sz; from++)
                col = (col + (long long)Tp[from][to] * init[from]) % MOD;
            ans = (ans + col) % MOD;
        }
        return ans;
    }
};