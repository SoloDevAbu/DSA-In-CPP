#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int keyElement) {

    int start = 0;
    int end = size - 1;

    while (start <= end) {

        int mid = start + (end - start) / 2;

        if (arr[mid] == keyElement) {
            return mid;
        }

        // Go to right side
        if (arr[mid] < keyElement) {
            start = mid + 1;
        } else {
            // Go to left side
            end = mid - 1;
        }
    }
    return -1;
}

    //To find the peak element in a sorted element
int findpeak(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    while(start < end){

        int mid = start + (end - start)/2;
        
        if(arr[mid] < arr[mid + 1]){
            start = mid + 1;
        } else {
            end = mid;
        }
    }

    return start;
}

int main() {
    int even[6] = {2,4,6,8,10,12};
    int odd[5] = {1,3,5,7,9};

    int eventindex = binarySearch(even, 6, 6);
    cout << "Index of 6 is "<<eventindex << endl;

    int oddIndex = binarySearch(odd, 5, 7);
    cout<< "Index of 7 is "<< oddIndex << endl;
}