class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;

        int cnt=0;

        for(int x : nums){
            minHeap.push(x);
        }

        while(minHeap.top() < k){
            long long x=minHeap.top();
            minHeap.pop();

            long long y=minHeap.top();
            minHeap.pop();

            //wrong as x : min and y : max already
            // long long int sum = (long long)min(x, y) * 2 + max(x, y);

            long long sum = x * 2 + y;

            minHeap.push(sum);

            cnt++;
        }

        return cnt;
    }
};