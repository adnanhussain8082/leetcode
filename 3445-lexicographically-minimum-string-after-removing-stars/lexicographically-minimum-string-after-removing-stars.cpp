class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<int> toRemove(n, 0);             // Marks characters to be removed
        vector<vector<int>> mp(26);             // Tracks indices of each character

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (!mp[c - 'a'].empty()) {
                        int idx = mp[c - 'a'].back();
                        toRemove[idx] = 1;      // Mark that smallest char for removal
                        mp[c - 'a'].pop_back(); // Remove it from tracking
                        break;                  // Only remove one character per '*'
                    }
                }
            } else {
                mp[s[i] - 'a'].push_back(i);    // Track index of this character
            }
        }

        string ans = "";
        for (int i = 0; i < n; i++) {
            if (!toRemove[i] && s[i] != '*') {
                ans += s[i];                    // Keep only valid characters
            }
        }

        return ans;
    }
};
