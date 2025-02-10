class Solution {
public:
    string clearDigits(string s) {
        int n=s.size();
        string res = "";

        for(auto& ch : s){
            if(isdigit(ch)){
                res.pop_back();
            }
            else{
                res.push_back(ch);
            }
        }
        return res;
    }
};