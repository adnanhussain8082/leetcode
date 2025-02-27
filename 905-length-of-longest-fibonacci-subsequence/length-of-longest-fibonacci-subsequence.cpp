class Solution {
public:
    // int lenLongestFibSubseq(vector<int>& arr) {
        // int lenLongestFibSubseq(vector<int>& A) {
        // unordered_set<int> s(A.begin(), A.end());
        // int res = 0;
        // for (int i = 0; i < A.size(); ++i) {
        //     for (int j = i + 1; j < A.size(); ++j) {
        //         int  a = A[i], b = A[j], l = 2;
        //         while (s.count(a + b))
        //             b = a + b, a = b - a, l++;
        //         res = max(res, l);
        //     }
        // }
        // return res > 2 ? res : 0;


        //               dp solution

        int lenLongestFibSubseq(vector<int>& A) {
        unordered_map<int, int> m;
        int N = A.size(), res = 0;
        int dp[N][N];
        for (int j = 0; j < N; ++j) {
            m[A[j]] = j;
            for (int i = 0; i < j; ++i) {
                int k = m.find(A[j] - A[i]) == m.end() ? -1 : m[A[j] - A[i]];
                dp[i][j] = (A[j] - A[i] < A[i] && k >= 0) ? dp[k][i] + 1 : 2;
                res = max(res, dp[i][j]);
            }
        }
        return res > 2 ? res : 0;
    }
};