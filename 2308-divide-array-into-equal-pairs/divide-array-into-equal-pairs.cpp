class Solution {
private: 
    bool approach1(vector<int>& nums){
        int n=nums.size();
        unordered_map<int,int> mpp;

        for(auto& it : nums){
            mpp[it]++;
        }

        int pairs=0;

        for(auto& it : mpp){
            pairs += it.second/2;
        }

        return pairs == n/2;
    }

    bool approach2(vector<int>& nums){
        int n=nums.size();

        sort(nums.begin(),nums.end());

        int i=1;
        for(;i<n;){
            if(nums[i]==nums[i-1]){
                i+=2;
            }
            else{
                return false;
            }
        }
        return true;
    }
public:
    // General Rule of Thumb:
    // If N ≤ 10⁵, sorting (O(N log N)) is manageable.
    // If N ≥ 10⁶, prefer O(N) time, even if it uses O(N) space.

    bool divideArray(vector<int>& nums) {

        //approach 1:
        // return approach1(nums);

        //approach 2:
        return approach2(nums);

    }
};