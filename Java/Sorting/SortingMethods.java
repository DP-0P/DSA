import java.util.Arrays;

public class SortingMethods {
    public static void main(String[] args) {
        int n[] = { 64, 34, 25, 12, 22, 11, 90 };
        System.out.println(Arrays.toString(n));
        bubbleSorting(n);
        System.out.println(Arrays.toString(n));
    }

    
    public static void bubbleSorting(int n[]) {

        for (int i = 0; i < n.length; ++i) {
            for (int j = 0; j < n.length - i - 1; ++j) {
                if (n[j] > n[j + 1]) {
                    n[j] ^= n[j + 1];
                    n[j + 1] ^= n[j];
                    n[j] ^= n[j + 1];
                }
            }
        }
        System.out.println(Arrays.toString(n));
    }
}
