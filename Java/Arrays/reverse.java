public class reverse{
    public static void reverseArray(int Array[]) {
        int start, end;
        int temp;
        start = 0;
        end = Array.length - 1;
        while (start < end) {
            temp = Array[start];
            Array[start] = Array[end];
            Array[end] = temp;
            start++;
            end--;
        }
    }
}
