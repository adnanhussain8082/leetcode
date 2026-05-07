class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());

        int best=0;

        for(int x : s){
            if(s.find(x-1)==s.end()){
                int y=x+1;

                while(s.find(y)!=s.end()){
                    y++;
                }

                best = max(best , y-x);
            }
        }

        return best;
    }
};