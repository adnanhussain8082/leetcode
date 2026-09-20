class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,vector<int>>> maxHeap;

        for(int i=0;i<points.size();i++){
            maxHeap.push({points[i][0]*points[i][0]+points[i][1]*points[i][1] , points[i]});
            //i did not used sqrt , still distances will be in same order

            //check
            if(maxHeap.size() > k) maxHeap.pop();
        }

        while(!maxHeap.empty()){
            vector<int> p = maxHeap.top().second;
            maxHeap.pop();
            ans.push_back(p);
        }
        return ans;
    }
};