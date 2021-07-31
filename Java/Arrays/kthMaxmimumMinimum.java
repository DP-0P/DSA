import java.util.Arrays;

public class kthMaxmimumMinimum {
    public static void KthElement(int array[]) {
        int k = 2;

        for (int i = 0; i < array.length - 1; i++) {
            for (int j = 0; j < array.length - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
        System.out.println(Arrays.toString(array));
        System.out.println("Kth largest element : " + array[k + 1]);
        System.out.println("Kth smallest element : " + array[k - 1]);
    }

    public static void main(String[] args) {
        int array[] = { 6, 4, 5, 2, 1, 3 };
        KthElement(array);
    }
}