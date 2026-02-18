class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, 0);

        queue<int> q;
        q.push(start);
        vis[start] = 1;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            if (arr[cur] == 0) return true;

            int forward = cur + arr[cur];
            int backward = cur - arr[cur];

            if (forward < n && !vis[forward]) {
                q.push(forward);
                vis[forward] = 1;
            }

            if (backward >= 0 && !vis[backward]) {
                q.push(backward);
                vis[backward] = 1;
            }
        }

        return false;
    }
};
