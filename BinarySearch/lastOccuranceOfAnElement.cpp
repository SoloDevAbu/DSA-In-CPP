#include<vector>
using namespace std;

int lastOcc(vector<int>& arr, int size, int key) {

    int start = 0, end = size - 1;
    int ans = -1;

    while(start <= end) {

        int mid = start + (end - start) / 2;

        if(arr[mid] == key) {
            ans = mid;
            //Storing the answer if there is no element in the right side and update the start to check is there any same elements present
            start = mid + 1;
        } else if(key> arr[mid]) {
            //To find the element in the right side of mid
            start = mid + 1;
        } else {
            //There is no element in the right side, so cheking in the left side of the vector
            end = mid - 1;
        }
    }

    //If found any element equals to key then it will return and if not then it will return -1
    return ans;
}