class Solution {
private:
    vector<int> counter(string& s){
        vector<int> temp(26,0);
        for(auto c : s){
            temp[c-'a']++;
        }
        return temp;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> count(26,0) , temp(26,0);
        vector<string> res;

        for(auto s : words2){
            temp = counter(s);
            for(int i=0;i<26;i++){
                count[i]=max(count[i],temp[i]);
            }
        }

        int i;
        for(auto s : words1){
            temp = counter(s);
            for(i=0;i<26;i++){
                if(temp[i]<count[i]){
                    break;
                }
            }
            if(i==26){
                res.push_back(s);
            }
        }
        return res;
    }
};