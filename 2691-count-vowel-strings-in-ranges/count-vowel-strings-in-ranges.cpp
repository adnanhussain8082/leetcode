class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        unordered_set<char> vowels = {'a','e','i','o','u'};
        vector<int> prefix(n+1 , 0);
        vector<int> ans;

        //store the prefix counts
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i] + (vowels.count(words[i].front()) && vowels.count(words[i].back()));
        }

        //get the queries and store answers
        for(auto arr : queries){
            int i=arr[0];
            int j=arr[1];
            ans.push_back(prefix[j+1]-prefix[i]);
        }

        return ans;
    }
};