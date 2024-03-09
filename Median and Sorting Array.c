#include <stdlib.h> // for malloc and free

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int nums3Size = nums1Size + nums2Size;
    int *nums3 = (int*)malloc(nums3Size * sizeof(int));
    if(nums3 == NULL) {
        // Handle memory allocation failure
        return -1; // or any appropriate error handling
    }

    // Copy elements from nums1 and nums2 to nums3
    int i, j;
    for (i = 0; i < nums1Size; i++) {
        nums3[i] = nums1[i];
    }

    for (i = 0, j = nums1Size; j < nums3Size && i < nums2Size; i++, j++) {
        nums3[j] = nums2[i];
    }

    // Sort nums3
    for (i = 0; i < nums3Size; i++) {
        for (j = i; j < nums3Size; j++) {
            if (nums3[i] > nums3[j]) {
                int temp = nums3[i];
                nums3[i] = nums3[j];
                nums3[j] = temp;
            }
        }
    }

    double median;
    if (nums3Size % 2 == 0) {
        median = (double)(nums3[nums3Size / 2 - 1] + nums3[nums3Size / 2]) / 2.0;
    } else {
        median = nums3[nums3Size / 2];
    }

    free(nums3); // Free dynamically allocated memory
    return median;
}
