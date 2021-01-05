public class array11_SingleDuplicate {
    public static int findDuplicate(int[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            for (int j = 0; j < array.length - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
        int c = 0;
        for (int i = 0; i < array.length; i++)
            for (int j = 0; j < array.length; j++)
                if (i != j)
                    if (array[i] == array[j])
                        c = array[i];
        return c;
    }
}
