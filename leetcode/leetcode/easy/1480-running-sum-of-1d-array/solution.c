int* runningSum(int* nums, int numsSize, int* returnSize) {
    // Allocate memory for the result array
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    // Calculate running sum
    for (int i = 0; i < numsSize; i++) {
        if (i == 0) {
            result[i] = nums[i];
        } else {
            result[i] = result[i - 1] + nums[i];
        }
    }
    return result;
}   