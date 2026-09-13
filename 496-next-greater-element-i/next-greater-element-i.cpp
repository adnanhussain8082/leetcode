class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreaterMap;
        stack<int> s;

        // Traverse nums2 to build the map of next greater elements
        for (int num : nums2) {
            while (!s.empty() && s.top() < num) {
                nextGreaterMap[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

        // Elements left in the stack do not have a next greater element
        while (!s.empty()) {
            nextGreaterMap[s.top()] = -1;
            s.pop();
        }

        // Prepare the result for nums1
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(nextGreaterMap[num]);
        }

        return ans;
    }
};
