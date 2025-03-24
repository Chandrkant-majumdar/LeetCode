
// class Solution {
// public:
//     int reverse(int x) {
//         int ans = 0; // Initialize the reversed number to 0
//         while (x != 0) {
//             int digit = x % 10; // Get the last digit of x
            
//             // Check for overflow/underflow before updating ans
//             if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
//                 return 0; // Return 0 if reversing x would cause overflow/underflow
//             }
            
//             ans = ans * 10 + digit; // Append the digit to the reversed number
//             x = x / 10; // Remove the last digit from x
//         }
//         return ans; // Return the reversed number
//     }
// };

class Solution {
public:
    int reverse(int x) {
       long long ans=0;
       cout<<pow(2,31)-1<<endl;
       while(x){
        if(ans*10>(pow(2,31)-1) || ans*10<(pow(-2,31))) return 0;
        
        ans=ans*10+(x%10);
        x/=10;
       }
       return (int)ans;
    }
};