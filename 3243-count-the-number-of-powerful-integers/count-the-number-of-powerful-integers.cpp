class Solution {
private:
    long long countValidNumbers(long long num, int limit, const string& suffix) {
        string strNum = to_string(num);
        int prefixLength = strNum.length() - suffix.length();

        if (prefixLength < 0) return 0;  // Number is too short to have the suffix

        // dp[i][tight] = number of valid prefixes of length i
        vector<vector<long long>> dp(prefixLength + 1, vector<long long>(2, 0));

        // Base case: if the suffix is valid
        dp[prefixLength][0] = 1;  // When not tight to num
        dp[prefixLength][1] = strNum.substr(prefixLength) >= suffix ? 1 : 0;

        for (int i = prefixLength - 1; i >= 0; --i) {
            int currentDigit = strNum[i] - '0';

            // Not tight: can choose any digit from 0 to limit
            dp[i][0] = (limit + 1) * dp[i + 1][0];

            // Tight: can choose digits from 0 to currentDigit
            if (currentDigit <= limit) {
                dp[i][1] = (long long)currentDigit * dp[i + 1][0] + dp[i + 1][1];
            } else {
                dp[i][1] = (long long)(limit + 1) * dp[i + 1][0];
            }
        }

        return dp[0][1];
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string suffix) {
        return countValidNumbers(finish, limit, suffix) - countValidNumbers(start - 1, limit, suffix);
    }
};
