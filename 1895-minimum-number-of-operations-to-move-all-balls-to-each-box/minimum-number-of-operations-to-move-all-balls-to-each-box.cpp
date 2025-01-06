class Solution {
public:
    //dp[i] = dp[i - 1] + (1 * balls) where balls is count(cnt)
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int> res(n,0);

        int ops=0 , cnt=0;

        //ist iteration : left to right
        for(int i=0;i<n;i++){
            res[i] += ops;
            cnt += (boxes[i]=='1') ? 1 : 0;
            ops += cnt;
        }

        //reinitialise ops and cnt
        ops=0 , cnt=0;

        //2nd iteration : right to left
        for(int i=n-1;i>=0;i--){
            res[i] += ops;
            cnt += (boxes[i]=='1') ? 1 : 0;
            ops += cnt;
        }
        return res;
    }
};