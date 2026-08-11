class Solution {
    public int missingInteger(int[] nums) {

        int sum = nums[0];

        // Step 1: Find the sum of the longest
        // sequential prefix.
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }

        // Step 2: Start checking from the prefix sum.
        int x = sum;

        while (true) {
            boolean found = false;

            // Check whether x exists in the array.
            for (int num : nums) {
                if (num == x) {
                    found = true;
                    break;
                }
            }

            // x is the first missing integer.
            if (!found) {
                return x;
            }

            // x exists, so try the next integer.
            x++;
        }
    }
}