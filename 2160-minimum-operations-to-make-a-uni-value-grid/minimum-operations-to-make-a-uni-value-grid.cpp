class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> flattened;

        for(auto& row : grid){
            flattened.insert(end(flattened) , begin(row) , end(row));
        }

        sort(flattened.begin(),flattened.end());

        int median = flattened[flattened.size()/2];

        int steps=0;

        for(int i=0;i<flattened.size();i++){
            if(abs(median - flattened[i])%x){
                return -1;
            }
            
            steps += abs(median - flattened[i])/x;
        }
        return steps;
    }
};