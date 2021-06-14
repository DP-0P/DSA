import java.util.Arrays;
public class InsertionSort {
    public static void InsertionSort(int array[]) {
        for (int i = 1; i < array.length; ++i) {
            int temp = array[i];
            int j = i - 1;
            for (; j >= 0 && array[j] > temp; j--)
                array[j + 1] = array[j];
            array[j + 1] = temp;
        }
        System.out.println(Arrays.toString(array));
    }
}

// Best Case - O(n) when array is already sorted
// Worst Case - O(n^2) when array is sorted in descending order
// Average Case - O(n^2)
// Space complexity - O(1)