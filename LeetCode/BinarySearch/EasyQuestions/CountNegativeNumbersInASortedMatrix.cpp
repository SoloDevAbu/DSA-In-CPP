/*
1351. Count Negative Numbers in a Sorted Matrix

Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

Example 1:
Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:
Input: grid = [[3,2],[1,0]]
Output: 0
*/

//CODE:

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int rowIndex = row - 1;
        int colIndex = 0;

        int count = 0;

        while(rowIndex >= 0 && colIndex < col){

            int element = grid[rowIndex][colIndex];

            if(element < 0){
                count += col - colIndex;
                rowIndex--;
            }else{
                colIndex++;
            }
        }

        return count;
    }
};