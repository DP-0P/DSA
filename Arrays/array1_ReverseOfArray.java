package Arrays;
public class array1_ReverseOfArray{
    static <E> void reverseArray(E Array[]) {
        int start, end;
        E temp;
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