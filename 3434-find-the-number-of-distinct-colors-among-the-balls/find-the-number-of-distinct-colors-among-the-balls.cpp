class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;

        unordered_map<int,int> btc; //ball to color map
        unordered_map<int,int> color; //stores freq of distinct colors

        int distinct=0;

        for(auto& x : queries){
            int ball_id=x[0] , c=x[1]; //c==color

            if(btc.count(ball_id)){
                if(--color[btc[ball_id]]==0) distinct--;
            }
            btc[ball_id]=c;

            if(++color[c]==1) distinct++;

            ans.push_back(distinct);
        }
        return ans;
    }
};