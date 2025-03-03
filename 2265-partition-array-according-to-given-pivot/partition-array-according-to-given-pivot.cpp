// class Solution {
// private:
//     vector<int> usingExtraSpace(vector<int>& nums, int pivot, )
// public:
//     vector<int> pivotArray(vector<int>& nums, int pivot) {
//         int n=nums.size();

//         vector<int> ans;

//         int cnt = count(nums.begin(),nums.end(),pivot);

//         for(auto& it : nums){
//             if(it < pivot) ans.push_back(it);
//         }

//         while(cnt){
//             ans.push_back(pivot);
//             cnt--;
//         }

//         for(auto& it : nums){
//             if(it > pivot) ans.push_back(it);
//         }

//         return ans;
//     }
// };


class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result(nums.size(), 0);
        int left = 0, right = nums.size() - 1;
        
        for (int i = 0, j = nums.size() - 1; i < nums.size(); ++i, --j) {
            if (nums[i] < pivot) {
                result[left] = nums[i];
                left++;
            }
            
            if (nums[j] > pivot) {
                result[right] = nums[j];
                right--;
            }
        }
        
        while (left <= right) {
            result[left] = pivot;
            left++;
        }
        
        return result;
    }
};