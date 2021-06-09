import java.util.Arrays;
import java.util.Scanner;

public class rotation {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int terms = sc.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();

        arr = arrayRotation(arr, terms);

        for (int i = 0; i < n; i++)
            System.out.print(arr[i] + " ");
    }

    static int[] arrayRotation(int[] arr, int terms) {

        int updated[] = new int[arr.length];

        for (int i = 0; i < arr.length; i++)
            updated[(i + arr.length - terms) % arr.length] = arr[i];

        return updated;
    }
}