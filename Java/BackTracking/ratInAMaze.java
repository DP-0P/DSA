public class ratInAMaze {
    public static void main(String[] args) {
        int n = 4;
        int array[][] = { { 1, 0, 0, 0 }, { 1, 1, 0, 1 }, { 0, 1, 0, 0 }, { 1, 1, 1, 1 } };

        int sol[][] = new int[n][n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                sol[i][j] = 0;

        if (ratInAMaze(array, 0, 0, n, sol))
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    System.out.print(sol[i][j] + " ");

                System.out.println();
            }
    }

    public static boolean isSafe(int array[][], int x, int y, int n) {
        if (x < n && y < n && array[x][y] == 1)
            return true;

        return false;
    }

    public static boolean ratInAMaze(int array[][], int x, int y, int n, int sol[][]) {
        if (x == n - 1 && y == n - 1) {
            sol[x][y] = 1;
            return true;
        }

        if (isSafe(array, x, y, n)) {
            sol[x][y] = 1;
            if (ratInAMaze(array, x + 1, y, n, sol))
                return true;

            if (ratInAMaze(array, x, y + 1, n, sol))
                return true;

            sol[x][y] = 0; // backtracking
            return false;
        }
        return false;
    }
}
