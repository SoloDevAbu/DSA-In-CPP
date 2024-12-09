/*
2529. Maximum Count of Positive Integer and Negative Integer
Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.
In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
Note that 0 is neither positive nor negative.

Example 1:
Input: nums = [-2,-1,-1,1,2,3]
Output: 3
Explanation: There are 3 positive integers and 3 negative integers. The maximum count among them is 3.

Example 2:
Input: nums = [-3,-2,-1,0,0,1,2]
Output: 3
Explanation: There are 2 positive integers and 3 negative integers. The maximum count among them is 3.

Example 3:
Input: nums = [5,20,66,1314]
Output: 4
Explanation: There are 4 positive integers and 0 negative integers. The maximum count among them is 4.
*/

//CODE:

class Solution {
public:
    int nCount(vector<int> nums){
        int s=0, e=nums.size() - 1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid] >= 0){
                e = mid -1;
            }else{
                s = mid + 1;
            }
        }
        return s;
    }
    int pCount(vector<int> nums){
        int s=0, e=nums.size() - 1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid] <= 0){
                s = mid +1;
            }else{
                e = mid - 1;
            }
        }
        return nums.size() - s;
    }
    int maximumCount(vector<int>& nums) {
        int positiveCount = pCount(nums);
        int negativeCount = nCount(nums);

        if(positiveCount > negativeCount){
            return positiveCount;
        }else{
            return negativeCount;
        }
    }
};