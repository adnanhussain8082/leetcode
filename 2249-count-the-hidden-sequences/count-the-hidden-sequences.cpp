class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        //check the notes

        long a=0 , mi=0 , ma=0;

        for(int d : differences){
            a += d;
            ma = max(ma , a);
            mi = min(mi , a);
        }

        return  max(0L , (upper-lower)-(ma-mi)+1);
    }
};