import java.util.Arrays;
public class BubbleSort {
    public static void bubbleSort(int array[]) {

        for (int i = 0; i < array.length; i++) {
            boolean swap = false;
            for (int j = 0; j < array.length - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    swap = true;
                    array[j] ^= array[j + 1];
                    array[j + 1] ^= array[j];
                    array[j] ^= array[j + 1];
                }
            }
            if (!swap) //if array is already sorted loop will break
                break;
        }
        System.out.println(Arrays.toString(array));
    }
}

// Time Complexity -
// Best Case - n when array is already sorted
// Worst Case - O(n^2)
// Average Case - O(n^2)

// Space complexity - O(1)