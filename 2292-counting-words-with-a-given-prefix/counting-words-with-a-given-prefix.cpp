class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int m=pref.size();
        int count=0;

        for(auto word : words){
            if(word.substr(0 , m)==pref){
                count++;
            }
        }
        return count;
    }
};