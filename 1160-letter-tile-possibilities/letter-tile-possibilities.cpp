class Solution {
private:
    int dfs(vector<int>& countt){
        int sum=0;
        for(int i=0;i<26;i++){
            if(countt[i]==0) continue;

            sum++;
            countt[i]--;
            sum += dfs(countt);
            countt[i]++; //backttracking
        }
        return sum;
    }
public:
    int numTilePossibilities(string tiles) {
        vector<int> countt(26,0);

        for(auto ch : tiles){
            countt[ch - 'A']++;
        }

        return dfs(countt);
    }
};