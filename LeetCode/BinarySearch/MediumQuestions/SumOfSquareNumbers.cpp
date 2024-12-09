/*
633. Sum Of Square Of Numbers

Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:
Input: c = 3
Output: false
*/

//CODE:

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a =0, b = sqrt(c);

        while(a <= b){
            long long ans = (a*a) + (b*b);
            if(ans == c){
                return true;
            }
            if(ans < c){
                a++;
            }else{
                b--;
            }
        }
        return false;
    }
};