// class Solution {
// public:
//     long long repairCars(vector<int>& ranks, int cars) {
//         //left=0
//         //right = 100 * 1e6 * 1e6 == 1e14

//         long long left=0 , right=1e14;

//         while(left<right){
//             int mid = left + (right-left)/2;

//             long long carss=0;
//             for(auto& it : ranks){
//                 carss += (long long)sqrt(mid / it); 
//             }

//             if(carss>=cars){
//                 right=mid;
//             }
//             else{
//                 left=mid+1;
//             }
//         }
//         return left;
//     }
// };

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 0, right = 1e14;  // Ensure right is large enough
        
        while (left < right) {
            long long mid = left + (right - left) / 2;  // Use long long for mid

            long long carss = 0;
            for (auto& it : ranks) {
                carss += (long long)sqrt(mid / it);  // Ensure integer division doesn't cause issues
            }

            if (carss >= cars) {
                right = mid;  // Correct the binary search narrowing
            } else {
                left = mid + 1;  // Ensure left progresses correctly
            }
        }
        return left;
    }
};