class Solution {
public:
    // Use dp[i] to record the number of good strings of length i.
    vector<int> dp;
    const int mod = 1e9+7;

    // Find the number of good strings of length `end`.
    int dfs(int end, int zero, int one) {
        if (dp[end] != -1)
            return dp[end];
        int count = 0;
        if (end >= one) {
            count = (count + dfs(end - one, zero, one)) % mod;
        }
        if (end >= zero) {
            count = (count + dfs(end - zero, zero, one)) % mod;
        }
        dp[end] = count;
        return dp[end];
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        dp.assign(high + 1, -1);
        dp[0] = 1;

        // Add up the number of strings with each valid length [low ~ high].
        int answer = 0;
        for (int end = low; end <= high; ++end) {
            answer = (answer + dfs(end, zero, one)) % mod;
        }
        return answer;
    }
};
