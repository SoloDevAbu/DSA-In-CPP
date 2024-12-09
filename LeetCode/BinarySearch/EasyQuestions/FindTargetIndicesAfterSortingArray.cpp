/*
2089. Find Target Indices After Sorting Array
You are given a 0-indexed integer array nums and a target element target.
A target index is an index i such that nums[i] == target.
Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list. The returned list must be sorted in increasing order.

Example 1:
Input: nums = [1,2,5,2,3], target = 2
Output: [1,2]
Explanation: After sorting, nums is [1,2,2,3,5].
The indices where nums[i] == 2 are 1 and 2.

Example 2:
Input: nums = [1,2,5,2,3], target = 3
Output: [3]
Explanation: After sorting, nums is [1,2,2,3,5].
The index where nums[i] == 3 is 3.

Example 3:
Input: nums = [1,2,5,2,3], target = 5
Output: [4]
Explanation: After sorting, nums is [1,2,2,3,5].
The index where nums[i] == 5 is 4.
*/

//CODE:

class Solution {
public:
    int firstOcr(vector<int>& arr, int target){
        int s=0, e = arr.size() - 1;

        int ans = -1;

        while(s<= e){
            int mid = s+(e-s)/2;

            if(arr[mid] == target){
                ans = mid;
                e = mid -1;
            }else if(arr[mid] < target){
                s = mid + 1;
            }else{
                e = mid -1;
            }
        }

        return ans;
    }
    int lastOcr(vector<int>& arr, int target){
        int s=0, e = arr.size() - 1;

        int ans = -1;

        while(s<= e){
            int mid = s+(e-s)/2;

            if(arr[mid] == target){
                ans = mid;
                s = mid +1;
            }else if(arr[mid] < target){
                s = mid + 1;
            }else{
                e = mid -1;
            }
        }

        return ans;
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;

        int firstIndex = firstOcr(nums, target);
        int lastIndex = lastOcr(nums, target);

        if(firstIndex == -1 || lastIndex == -1 ){
            return ans;
        }
        for(int i =firstIndex; i <= lastIndex; i++){
                ans.push_back(i);
            }

        return ans;
    }
};