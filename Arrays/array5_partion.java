package Arrays;

public class array5_partion {
    public static int[] partion(int[] array) {
        int j = 0;
        for (int i = 0; i < array.length; i++) {
            if (array[i] < 0) {
                if (i != j) {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
                j++;
            }
        }
        return array;
    }
}
