class Solution {
public:
    long long minSum(vector<int>& a, vector<int>& b) {
        long long sa=0 , sb=0 , a0=0 , b0=0;

        for(auto& i : a){
            a0 += (i==0) ? 1 : 0;
            sa += (i==0) ? 1 : i;
        }
        for(auto& i : b){
            b0 += (i==0) ? 1 : 0;
            sb += (i==0) ? 1 : i;
        }

        if(sa > sb && b0 == 0) return -1;
        if(sb > sa && a0 == 0) return -1;

        return max(sa , sb);
    }
};