class Solution {
private:
    void dfs(int node, vector<vector<int>>& gr, vector<int>& fromNode, int dist) {
        if (fromNode[node] <= dist) return;  // Already visited with a shorter distance
        fromNode[node] = dist;

        for (int ne : gr[node]) {
            dfs(ne, gr, fromNode, dist + 1);
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> gr(n);

        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) {
                gr[i].push_back(edges[i]);
            }
        }

        vector<int> fromNode1(n, 1e6);
        vector<int> fromNode2(n, 1e6);

        dfs(node1, gr, fromNode1, 0);
        dfs(node2, gr, fromNode2, 0);

        int minDist = 1e6;
        int minIdx = -1;

        for (int i = 0; i < n; i++) {
            if (fromNode1[i] != 1e6 && fromNode2[i] != 1e6) {
                int maxDist = max(fromNode1[i], fromNode2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    minIdx = i;
                }
            }
        }
        return minIdx;
    }
};
