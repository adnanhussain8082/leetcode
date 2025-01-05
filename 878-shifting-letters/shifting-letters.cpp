class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        // int n = s.size();

        // long long shift=accumulate(shifts.begin(),shifts.end(),0LL);

        // for(int i=0;i<n;i++){
        //     s[i] = 'a' + (s[i]-'a' + shift%26)%26;
        //     shift -= shifts[i];
        // }
        // return s;


        // 2nd approach does not use long long but works from n-1 to 0(reverse)

        int n=s.size();
        int shift=0;

        for(int i=n-1;i>=0;i--){
            shift = (shift + shifts[i])%26;
            s[i] = 'a' + (s[i]-'a' + shift)%26;
        }
        return s;
    }
};