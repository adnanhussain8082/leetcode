// class Solution {
// public:
//     int minOperations(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]>=k){
//                 return i;
//             }
//         }
//         return -1;
        
//     }
// };


class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<k){
                cnt++;
            }
        }
        return cnt;
    }
};