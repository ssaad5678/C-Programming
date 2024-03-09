#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int uniqueCount = 1;
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[uniqueCount] = nums[i];
            uniqueCount++;
        }
    }
    
    return uniqueCount;
}

int main() {
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    int expectedNums[] = {0,1,2,3,4};
    int expectedSize = sizeof(expectedNums) / sizeof(expectedNums[0]);
    
    int k = removeDuplicates(nums, numsSize);
    
    printf("Expected unique count: %d\n", expectedSize);
    printf("Actual unique count: %d\n", k);
    printf("Expected nums array: ");
    for (int i = 0; i < expectedSize; i++) {
        printf("%d ", expectedNums[i]);
    }
    printf("\nActual nums array: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    return 0;
}
