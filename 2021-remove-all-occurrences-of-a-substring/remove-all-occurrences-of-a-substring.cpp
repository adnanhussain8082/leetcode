                    //iterative method
// class Solution {
// public:
//     string removeOccurrences(string s, string part) {
//         int pos = s.find(part);
//         while(pos!=string::npos){
//             s.erase(pos , part.length());
//             pos = s.find(part);
//         }
//         return s;
//     }
// };

                      //recursive method

class Solution {
public:
    void removeOCCRE(string& s , string& part){
        int found = s.find(part);

        if(found!=string::npos){
            //part string has been located
            //removing it using prefix and suffix string

            string left=s.substr(0,found);
            string right=s.substr(found+part.size(),s.size());
            s=left+right;  //updating the original string

            removeOCCRE(s,part);  //calling func
        }

        else{
            //base case
            return;
        }
    }
    string removeOccurrences(string s, string part) {
        removeOCCRE(s,part);
        return s;
    }
};