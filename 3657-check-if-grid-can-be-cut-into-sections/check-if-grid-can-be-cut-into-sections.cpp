class Solution {
private:
    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {}; // Edge case: no intervals

    // Step 1: Sort intervals based on start time
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    int start = intervals[0][0], end = intervals[0][1];

    // Step 2: Merge overlapping intervals
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] < end) { 
            // Overlapping intervals, extend the current interval
            end = max(end, intervals[i][1]);
        } else { 
            // Non-overlapping interval, push previous one and start a new one
            merged.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }

    // Step 3: Add the last interval
    merged.push_back({start, end});

    return merged;
}

public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> vertical;
        vector<vector<int>> horizontal;
        for(auto it: rectangles){
            vertical.push_back({it[1],it[3]}); // vertical view
            horizontal.push_back({it[0],it[2]}); // horizontal view
        }
        vector<vector<int>> mergeH= mergeIntervals(horizontal);
        vector<vector<int>> mergev= mergeIntervals(vertical);
        return mergeH.size()>=3 || mergev.size()>=3;
    }
};