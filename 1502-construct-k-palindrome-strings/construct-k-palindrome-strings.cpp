class Solution {
public:
    bool canConstruct(string s, int k) {
       //check Note for explaination
       bitset<26> odd;

       for(auto& c : s){
        odd.flip(c-'a');
       }

       return odd.count()<=k && k<=s.size();
    }
};