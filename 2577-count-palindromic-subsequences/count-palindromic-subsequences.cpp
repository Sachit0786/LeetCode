class Solution {
public:
    long long dp_l[10005][10][11];
    long long dp_r[10005][10][11];
    int countPalindromes(string s) {
        int n = s.size();
        long long mod = 1000000007;
        if ( n < 5 ) return 0;
        // pre-compute dp_l[i][j][k] from left to right
        for ( int i=1; i<n; ++i ) {
            for ( int j=0; j<10; ++j ) {
                for ( int k=0; k<10; ++k ) {
                    dp_l[i][j][k] = dp_l[i-1][j][k];
                }
            }
            for ( int j=0; j<10; ++j ) dp_l[i][j][s[i-1]-'0'] += dp_l[i-1][j][10];
            for ( int j=0; j<10; ++j ) dp_l[i][j][10] = dp_l[i-1][j][10];
            dp_l[i][s[i-1]-'0'][10]++;
        }
        // pre-compute dp_r[i][j][k] from right to left
        for ( int i=n-2; i>=0; --i ) {
            for ( int j=0; j<10; ++j ) {
                for ( int k=0; k<10; ++k ) {
                    dp_r[i][j][k] = dp_r[i+1][j][k];
                }
            }
            for ( int j=0; j<10; ++j ) dp_r[i][s[i+1]-'0'][j] += dp_r[i+1][j][10];
            for ( int j=0; j<10; ++j ) dp_r[i][j][10] = dp_r[i+1][j][10];
            dp_r[i][s[i+1]-'0'][10]++;
        }
        // compute final answer
        long long ans = 0;
        for ( int i=2; i<n-2; ++i ) {
            for ( int j=0; j<10; ++j ) {
                for ( int k=0; k<10; ++k ) {
                    ans = (ans + dp_l[i][j][k]*dp_r[i][k][j]%mod) % mod;
                }
            }
        }
        return ans;
    }
};