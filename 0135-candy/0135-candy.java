class Solution {
    public int candy(int[] ratings) {
        int length = ratings.length; 
        int[] res = new int[length];
        Arrays.fill(res, 1);
        int[] prefix = new int[length];
        Arrays.fill(prefix, 1);
        for (int index = 1; index < length; index++) {
            if (ratings[index] > ratings[index - 1]) {
                prefix[index] += prefix[index - 1];
            }
            res[index] = prefix[index];
        }

        Arrays.fill(prefix, 1);       
        for (int index = length - 2; index >= 0; index--) {
            if (ratings[index] > ratings[index + 1]) {
                prefix[index] += prefix[index + 1];
            }
            res[index] = Math.max(res[index], prefix[index]);
        }

        return Arrays.stream(res).sum();
    }
}