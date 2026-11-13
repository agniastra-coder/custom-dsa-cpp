int findLengthOfLCIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int currC = 1;
    int maxC = currC;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            currC++;
        } else {
            currC = 1;
        }
        maxC = maxC < currC ? currC : maxC;
    }

    return maxC;
}
