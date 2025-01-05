class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();

        long long shift=accumulate(shifts.begin(),shifts.end(),0LL);

        for(int i=0;i<n;i++){
            s[i] = 'a' + (s[i]-'a' + shift%26)%26;
            shift -= shifts[i];
        }
        return s;
    }
};