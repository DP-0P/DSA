import java.util.Scanner;

public class array3_KthElement {
    public static void KthEle(int array[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Kth Element");
        int k = sc.nextInt();

        for (int i = 0; i < array.length - 1; i++) {
            for (int j = 0; j < array.length - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
        System.out.println("Kth largest element : " + array[k + 1]);
        System.out.println("Kth smallest element : " + array[k - 1]);
    }
}
