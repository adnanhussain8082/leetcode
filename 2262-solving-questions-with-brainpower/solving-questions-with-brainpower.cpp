class Solution {
private:
    //method1: simple rec
    long long rec(vector<vector<int>>& questions, int i) {
        if (i >= questions.size()) return 0; // Base case: No more questions to solve

        int points = questions[i][0], bp = questions[i][1];
        int nexti = i + bp + 1;

        // Choose to take the current question or skip it
        return max(points + rec(questions, nexti), rec(questions, i + 1));
    }

    //method2: dp
    long long rec2(vector<vector<int>>& questions, int i, vector<long long>& dp) {
        if (i >= questions.size()) return 0; // Base case: No more questions to solve

        // dp check
        if (dp[i] != -1) return dp[i];

        // Otherwise, continue
        int points = questions[i][0], bp = questions[i][1];
        int nexti = i + bp + 1;

        // Choose to take the current question or skip it
        return dp[i] = max(points + rec2(questions, nexti, dp), rec2(questions, i + 1, dp));
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        
        //method 1 
        // return rec(questions, 0);

        //method 2 : dp
        vector<long long> dp(n, -1); // 1D DP array initialized with -1
        return rec2(questions, 0, dp);
    }
};
