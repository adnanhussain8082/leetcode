class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();

        //sort the words in decreasing order of lengths of individal strings
        sort(words.begin(),words.end(), [](const string &a , const string &b){
            return a.size() > b.size();
        });

        vector<string> ans;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(words[i].find(words[j]) != string::npos){
                    // Add to result only if it's not already present(check Note)
                    if(find(ans.begin(),ans.end(),words[j]) == ans.end()){
                        ans.push_back(words[j]);
                    }
                }
            }
        }
        return ans;
    }
};