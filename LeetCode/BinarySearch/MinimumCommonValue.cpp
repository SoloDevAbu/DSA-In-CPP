/*
2540. Minimum Common Value

Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.
Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.

Example 1:
Input: nums1 = [1,2,3], nums2 = [2,4]
Output: 2
Explanation: The smallest element common to both arrays is 2, so we return 2.

Example 2:
Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
Output: 2
Explanation: There are two common elements in the array 2 and 3 out of which 2 is the smallest, so 2 is returned.
*/

//CODE:

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        int s1 = 0, s2=0, e1=nums1.size()-1, e2=nums2.size()-1;

        while(s1<=e1 && s2<=e2){

            if(nums1[s1] == nums2[s2]){
                return nums1[s1];
            }

            if(nums1[s1] < nums2[s2]){
                s1++;
            }else{
                s2++;
            }
        }

        return -1;
    }
};