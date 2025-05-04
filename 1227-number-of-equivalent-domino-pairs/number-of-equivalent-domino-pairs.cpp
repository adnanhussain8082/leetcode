class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,int> count;

        int res=0;
        for(auto& it : dominoes){
            int key = min(it[0],it[1])*10 + max(it[0],it[1]);
            count[key]++;
        }

        for(const auto& [key , val] : count){
            res += (val)*(val-1)/2; //n choose 2
        }

        return res;
    }
};