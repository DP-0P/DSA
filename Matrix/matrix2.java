public static void maxOnesInARow(int matrix[][]) {
    int max = 0;
    for (int i = 0; i < matrix.length; i++) {
        int cur = 0;
        for (int j = 0; j < matrix[i].length; j++) {
            if (matrix[i][j] == 1)
                cur++;
            if (cur > max)
                max = cur;
            }
        }
    System.out.println(max);
}
