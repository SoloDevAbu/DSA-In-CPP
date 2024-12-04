#include<iostream>
#include<vector>
using namespace std;

int firstOccurance(vector<int>& arr, int size, int key){
    int start = 0, end = size - 1;
    int ans = -1;

    while (start <= end){
        
        int mid = start + (end - start)/2;

        if(arr[mid]  == key){
            ans = mid;
            //Updating the mid, since it can have multiple element of key in a asorted array
            end = mid - 1;
        } else if(key > arr[mid]) {
            //Right part
            start = mid + 1;
        } else {
            //Left part
            end = mid - 1;
        }
    }

    //If answer doesn't exits the it will return -1
    return ans;
    
}