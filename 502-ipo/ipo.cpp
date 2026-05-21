class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> ventures;
        int n=profits.size();

        for(int i=0;i<profits.size();i++){
            ventures.push_back({capital[i],profits[i]});
        }

        sort(ventures.begin(),ventures.end());

        int money=w;
        priority_queue<int> maxHeap;

        int i=0;

        for(int j=0;j<k;j++){

            while(i<n && ventures[i].first<=money){
                maxHeap.push(ventures[i].second);
                i++;
            }

            if(maxHeap.empty()) break;

            money+=maxHeap.top();
            maxHeap.pop();
        }

        return money;


    }
};