public class maximumMinimum {
    public static void MaxMin(int[] array) {
        int max = array[0], min = array[0];
        for (int i = 0; i < array.length; i++) {
            if (array[i] > max)
                max = array[i];
            if (array[i] < min)
                min = array[i];
        }
        System.out.println("Largest Element " + max);
        System.out.println("Smallest Element " + min);
    }
    public static void main(String[] args) {
        int arr[] = {1,2845,3455,324,-1};
        MaxMin(arr);
    }
}
