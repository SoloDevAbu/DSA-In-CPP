/*
33. Search in Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1
*/

//CODE:

class Solution {
public:

    int getPivot(vector<int>& nums, int n) {
        int start = 0, end = n - 1;
        
        if (nums[start] < nums[end]) {
            return 0;
        }

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (mid < n - 1 && nums[mid] > nums[mid + 1]) {
                return mid + 1;
            }
            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                return mid;
            }
            if (nums[mid] >= nums[start]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return 0;
    }
    int binarySearch(vector<int>& nums, int s, int e, int k){
        int start = s, end = e;

        while(start <= end){
            int mid = start + (end - start) / 2;
            if(nums[mid] == k){
                return mid;
            }
            if(k > nums[mid]){
                start = mid + 1;
            } else{
                end = mid - 1;
            }
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = getPivot(nums, n);
        if(target >= nums[pivot] && target <= nums[n - 1]){
            return binarySearch(nums, pivot, n -1, target);
        } else {
            return binarySearch(nums, 0, pivot -1, target);
        }
    }
};