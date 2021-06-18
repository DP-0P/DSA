public class BinarySearch {
    public static void BinarySearchIterative(int[] array, int key) {
        int low = 0, high = array.length - 1, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (array[mid] == key) {
                System.out.println("Searched element is present at index " + mid);
                return;
            }
            else if (key > array[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        System.out.println("Searched element is not present in the array");
    }
    public static int BinarySearchRecursive(int[] array, int key, int low, int high) {
        while (low <= high) {
            int mid = (low + high) / 2;
            if (array[mid] == key)
                return mid;
            else if (key > array[mid])
                return BinarySearchRecursive(array, key, mid + 1, high);
            else
               return BinarySearchRecursive(array, key, low, mid - 1);
        }
        return -1;
    }
}
// Best Case - O(1)
// Worst Case - O(log n) when array is already sorted
// Average Case - O(log n)
// Space Complexity Recursive - O(log n)
// Space Complexity Iterative - O(1)
// Iterative method is better cause of space complexity