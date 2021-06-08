import java.util.Arrays;

public class SortingMethods {
    public static void main(String[] args) {
        int n[] = { 5, 7, 2, 7, 1, 9, 0 };
        System.out.println(Arrays.toString(n));
        selectionSort(n);
        System.out.println(Arrays.toString(n));
    }

    public static int[] bubbleSort(int n[]) {
        boolean swap;
        for (int i = 0; i < n.length; ++i) {
            swap = true;
            for (int j = 0; j < n.length - i - 1; ++j) {
                if (n[j] > n[j + 1]) {
                    n[j] ^= n[j + 1];
                    n[j + 1] ^= n[j];
                    n[j] ^= n[j + 1];
                    swap = true;
                }
            }
            if (!swap)
                break;
        }
        return n;
    }

    public static int[] insertionSort(int n[]) {
        for (int i = 1; i < n.length; ++i) {
            int temp = n[i];
            int j = i - 1;
            while (j >= 0 && n[j] > temp) {
                n[j + 1] = n[j];
                --j;
            }
            n[j + 1] = temp;
        }
        return n;
    }

    public static int[] selectionSort(int n[]){

        for(int i=0;i<n.length-1;i++){
            int min=i;
            for(int j=i+1;j<n.length;j++){
                if(n[min]>n[j])
                min = j;
            }
            
                int temp = n[min];
                n[min] = n[i];
                n[i] = temp;
        }
        return n;
    }
}
