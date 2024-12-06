# **Binary Search**

Binary Search is an efficient searching algorithm used to find the position of a target element in a **sorted array**. It works by repeatedly dividing the search interval in half, making it much faster than linear search for large datasets.

---

## **How It Works**
Binary Search follows these steps:

1. **Initial Setup:**  
   Set two pointers:  
   - `low` pointing to the beginning of the array.  
   - `high` pointing to the end of the array.  

2. **Find the Middle Element:**  
   Calculate the middle index using the formula:  
   ```cpp
   mid = low + (high - low) / 2;


(This avoids overflow compared to (low + high) / 2.)

1.  **Compare the Middle Element:**
    
    *   If the middle element matches the target, return its index.
        
    *   If the middle element is greater than the target, the target lies in the **left half** of the array. Update high = mid - 1.
        
    *   If the middle element is smaller than the target, the target lies in the **right half** of the array. Update low = mid + 1.
        
2.  **Repeat:**Continue dividing the array in half until the target is found or the search space becomes empty (low > high).
    

**Algorithm in C++**
--------------------

Here’s how Binary Search can be implemented iteratively:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] > target) {
            high = mid - 1; // Search in the left half
        } else {
            low = mid + 1; // Search in the right half
        }
    }

    return -1; // Target not found
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11}; // Sorted array
    int target = 5;

    int index = binarySearch(arr, target);
    if (index != -1) {
        cout << "Target found at index: " << index << endl;
    } else {
        cout << "Target not found." << endl;
    }

    return 0;
}
```

**Key Characteristics**
-----------------------

*   **Input Requirement:** The array must be sorted.
    
*   **Time Complexity:**
    
    *   Best case: O(1) (if the middle element is the target).
        
    *   Worst/Average case: O(log N), where N is the number of elements.
        
*   **Space Complexity:**
    
    *   Iterative approach: O(1) (no extra space).
        
    *   Recursive approach: O(log N) (due to recursion stack).
        

**When to Use Binary Search**
-----------------------------

*   Use Binary Search when:
    
    *   The dataset is sorted.
        
    *   Random access to array elements is possible (like in arrays, not linked lists).
        
    *   The size of the dataset is large, and efficiency is a concern.
        

Binary Search is a powerful algorithm that forms the basis for many advanced concepts in computer science, like search trees, heaps, and divide-and-conquer algorithms. Mastering Binary Search will enhance your problem-solving skills significantly!
