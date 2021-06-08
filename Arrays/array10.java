public class array10 {
    public static int MinJumps(int array[]) {
        int i = 0, temp = 0, c = 0, s = 0;
        while (true) {
            if (array[0] >= array.length - 1 || array.length == 1)
                return 1;
            temp = array[i];
            c++;
            s = s + temp;
            if (s >= array.length - 1)
                return c;
            i = i + temp;
        }
    }

    public static void main(String[] args) {
        int array[] = { 1, 2, 3, 4, 5 };
        System.out.println(MinJumps(array));
    }
}
