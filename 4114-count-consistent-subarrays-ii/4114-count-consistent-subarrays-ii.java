class Solution {
    public long countConsistent(int[] nums) {
        int N = nums.length;
        long ans = 0;
        int[] left = new int[N];
        int[] right = new int[N];
        {
            Stack<Integer> stack = new Stack<>();
            for (int i = 0; i < N; i++) {
                left[i] = i+1;
                while (!stack.isEmpty() && (nums[stack.peek()]&nums[i]) == nums[i] 
                ) {
                    stack.pop();
                }
                if (!stack.isEmpty())
                    left[i] = i - stack.peek();
                stack.push(i);
            }
        }
        {
            Stack<Integer> stack = new Stack<>();
            for (int i = N - 1; i >= 0; i--) {
                right[i] = N - i;
                while (!stack.isEmpty() && (nums[stack.peek()]&nums[i]) == nums[i] && nums[stack.peek()] > nums[i]) {
                    stack.pop();
                }
                if (!stack.isEmpty())
                    right[i] = stack.peek() - i;
                stack.push(i);
            }
        }
        for (int i = 0; i < N; i++) {
            ans += ((long)left[i] * right[i]);
        }
        return ans;
    }
}