public class QuickSort {
    public static void QuickSort(int[] array, int low, int high) {
        if (low < high) {
            int pivot = Partition(array, low, high);
            QuickSort(array, low, pivot - 1);
            QuickSort(array, pivot + 1, high);
        }
    }

    public static int Partition(int[] array, int low, int high) {
        int pivot = array[low];
        int i = low;
        int j = high;

        while (i < j) {
            while (array[i] <= pivot)
                i++;

            while (array[j] > pivot)
                j--;

            if (i < j) {
                array[i] ^= array[j];
                array[j] ^= array[i];
                array[i] ^= array[j];
            }
        }
        int temp = array[j];
        array[j] = array[low];
        array[low] = temp;
        return j;
    }
}
// Best Case - O(n log n) when pivot is the middle element and divides the array into equal sub-arrays
// Worst Case - O(n²) when array is already sorted
// Average Case - O(n log n)
// Worst Case Space Complexity - O(n)
// Worst Case Space Complexity - O(log n)
