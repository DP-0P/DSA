public class matrix1 {

    public static void spiralPrint(int matrix[][]) {

        int top = 0;
        int bottom = matrix.length - 1;

        int left = 0;
        int right = matrix[0].length - 1;

        while (true) {

            for (int i = left; i <= right; i++)
                System.out.println(matrix[top][i]);
            top++;

            for (int i = top; i <= bottom; i++)
                System.out.println(matrix[i][right]);
            right--;

            for (int i = right; i >= left; i--)
                System.out.println(matrix[bottom][i]);
            bottom--;

            for (int i = bottom; i >= top; i--)
                System.out.println(matrix[i][left]);
            left++;

        }
    }
}