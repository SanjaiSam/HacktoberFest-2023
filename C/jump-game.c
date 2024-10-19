#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
    int maxReach = 0;
    for (int i = 0; i < numsSize; i++) {
        // If the current index is beyond the maximum reach, we cannot proceed
        if (i > maxReach) {
            return false;
        }
        // Update the maximum reach
        if (i + nums[i] > maxReach) {
            maxReach = i + nums[i];
        }
        // If we've already reached or exceeded the last index, return true
        if (maxReach >= numsSize - 1) {
            return true;
        }
    }
    return false;
}

int main() {
    int size;

    // Get the size of the array from the user
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    // Check for valid size
    if (size <= 0) {
        printf("Array size must be greater than 0.\n");
        return 1;
    }

    // Dynamically allocate memory for the array
    int* nums = (int*)malloc(size * sizeof(int));
    if (nums == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Get the array elements from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
    }

    // Check if we can jump to the last index
    if (canJump(nums, size)) {
        printf("You can reach the last index.\n");
    } else {
        printf("You cannot reach the last index.\n");
    }

    // Free the allocated memory
    free(nums);
    
    return 0;
}
