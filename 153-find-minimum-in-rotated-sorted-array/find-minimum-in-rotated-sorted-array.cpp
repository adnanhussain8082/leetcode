class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            // If the mid element is greater than the end element, 
            // the smallest value is in the right part of the array
            if (nums[mid] > nums[end]) {
                start = mid + 1;
            }
            // Otherwise, the smallest value is in the left part (including mid)
            else {
                end = mid;
            }
        }

        // After the loop ends, start == end, which points to the smallest element
        return nums[start];
    }
};
