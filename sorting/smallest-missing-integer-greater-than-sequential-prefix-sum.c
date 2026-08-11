int missingInteger(int* nums, int numsSize) {
    int prefix_len = 1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1] + 1) {
            prefix_len += 1;
        } else {
            break;
        }
    }

    int total = (nums[prefix_len - 1] + nums[0]) * prefix_len / 2;
    bool found = true;

    while (found) {
        found = false;
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] == total) {
                found = true;
                total += 1;
                break;
            }
        }
    }

    return total;
}