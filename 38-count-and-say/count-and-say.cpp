class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string res = "1";
        
        for (int step = 2; step <= n; ++step) {
            string next = "";
            int len = res.length();
            
            for (int i = 0; i < len;) {
                int count = 1;
                while (i + count < len && res[i] == res[i + count]) {
                    ++count;
                }
                next += to_string(count) + res[i];
                i += count;
            }
            
            res = next;
        }
        
        return res;
    }
};
