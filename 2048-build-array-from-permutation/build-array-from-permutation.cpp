class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        //  method 1->0(n) space complexity
        // vector<int> ans;
        // for(int i=0;i<size(nums);i++){
        //     // swap(nums[i],nums[nums[i]]);
        //     ans.push_back(nums[nums[i]]);
        // }
        // return ans;

        //  method 2->0(1) space complexity
        //using a formulla here
        int n=size(nums);
        for(int i=0;i<n;i++){
            nums[i]+=n*(nums[nums[i]]%n);
        }
        for(int i=0;i<n;i++){
            nums[i]/=n;
        }
        return nums;

    }
};