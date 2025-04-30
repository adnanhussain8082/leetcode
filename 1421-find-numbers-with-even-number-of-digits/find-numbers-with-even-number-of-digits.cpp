class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;

        for(auto& it : nums){
            int numLen = to_string(it).length();
            if((numLen & 1) == 0) count++;
        }

        return count;
    }
};