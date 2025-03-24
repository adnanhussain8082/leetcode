


class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days; // No meetings, all days are free

        // Step 1: Sort meetings based on start time
        sort(meetings.begin(), meetings.end());

        // Step 2: Merge overlapping intervals
        int totalMeetingDays = 0;
        int start = meetings[0][0], end = meetings[0][1];

        for (int i = 1; i < meetings.size(); i++) {
            if (meetings[i][0] <= end + 1) { 
                // Overlapping or consecutive meetings, extend the interval
                end = max(end, meetings[i][1]);
            } else { 
                // Non-overlapping meeting, count previous interval
                totalMeetingDays += (end - start + 1);
                start = meetings[i][0];
                end = meetings[i][1];
            }
        }

        // Step 3: Add last merged meeting interval
        totalMeetingDays += (end - start + 1);

        // Step 4: Calculate free days
        return days - totalMeetingDays;
    }
};

