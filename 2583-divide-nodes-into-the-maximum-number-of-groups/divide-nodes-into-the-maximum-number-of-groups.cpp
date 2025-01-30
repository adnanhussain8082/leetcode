class Solution {
public:
    vector<int> gr[505];
    int color[505];
    bool isBipartite;
    vector<int> connectedComponentNodes;

    int getMaxDistanceFromNode(int source, int totalNodes) {
        vector<int> distance(totalNodes + 1, -1);
        queue<int> q;
        q.push(source);
        distance[source] = 1;
        int maxDistance = 1;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int &neighbor : gr[current]) {
                if (distance[neighbor] == -1) {
                    distance[neighbor] = distance[current] + 1;
                    q.push(neighbor);
                    maxDistance = max(maxDistance, distance[neighbor]);
                }
            }
        }
        return maxDistance;
    }

    void depthFirstSearch(int node, int currentColor = 1) {
        color[node] = currentColor;
        connectedComponentNodes.push_back(node);

        for (int &neighbor : gr[node]) {
            if (!color[neighbor]) {
                depthFirstSearch(neighbor, 3 - currentColor);
            } else if (color[neighbor] == currentColor) {
                isBipartite = false;
            }
        }
    }

    int magnificentSets(int n, vector<vector<int>> &edges) {
        for (int i = 1; i <= n; i++) gr[i].clear();
        memset(color, 0, sizeof color);

        for (auto &edge : edges) {
            gr[edge[0]].push_back(edge[1]);
            gr[edge[1]].push_back(edge[0]);
        }

        int maxGroups = 0;
        for (int i = 1; i <= n; i++) {
            if (color[i] == 0) {
                connectedComponentNodes.clear();
                isBipartite = true;

                depthFirstSearch(i);
                if (!isBipartite) return -1;

                int maxComponentDistance = 0;
                for (int &node : connectedComponentNodes) {
                    maxComponentDistance = max(maxComponentDistance, getMaxDistanceFromNode(node, n));
                }
                maxGroups += maxComponentDistance;
            }
        }
        return maxGroups;
    }
};