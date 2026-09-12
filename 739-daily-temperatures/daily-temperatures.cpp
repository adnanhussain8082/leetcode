class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int> results(n,0);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() and temp[st.top()]<temp[i]){
                results[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }

        return results;
    }
};