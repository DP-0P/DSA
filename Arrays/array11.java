public class array11 {
    public static int findDuplicate(int[] array) {
        int count=0;
        for (int i = 0; i < array.length - 1; i++) {
            for (int j = 0; j < array.length - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                    count++;
                }
            }
        }
        
        int c = 0;
        for (int i = 0; i < array.length; i++)
            for (int j = 0; j < array.length; j++)
                if (i != j)
                    if (array[i] == array[j])
                        c = array[i];
        return c;
    }
    public static void main(String[] args) {
        int[] array = {2, 3, 4, 5, 6, 5};
        System.out.println(findDuplicate(array));
    }
}
