#include<vector>
using namespace std;

int findPivot(vector<int> v){
    int start = 0, end = v.size() - 1;

    while(start < end){
        int mid = start + (end - start) / 2;

        if(v[mid] < v[mid + 1]){
            start = mid + 1;
        } else {
            end = mid;
        }
    }

    return start;
}

int peakIndexInMountainArray(vector<int>& arr) {
    return findPivot(arr);
}