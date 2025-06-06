class Solution {
public:
        long long putMarbles(vector<int> A, int k) {
        long long res = 0, n  = A.size() - 1;
        for (int i = 0; i < n; ++i)
            A[i] += A[i + 1];
        A.pop_back();
        nth_element(A.begin(), A.begin() + k - 1, A.end());
        for (int i = 0; i < k - 1; ++i)
            res -= A[i];
        nth_element(A.begin(), A.begin() + n - k + 1, A.end());
        for (int i = 0; i < k - 1; ++i)
            res += A[n - 1 - i];
        return res;
    }
};