import java.util.Arrays;
import java.util.HashSet;

public class array6 {
    public static void UnionAndIntersection(int array1[], int array2[]) {

        int intersectionLength = Math.min(array1.length, array2.length);

        int intersection[] = new int[intersectionLength];

        int intersectionCounter = 0;

        for (int i = 0; i < array1.length; i++) {
            for (int j = 0; j < array2.length; j++) {
                if (array1[i] == array2[j]) {
                    intersection[intersectionCounter] = array1[i];
                    intersectionCounter++;
                    break;
                }
            }
        }

        int union[] = new int[array1.length + array2.length];

        // have to work as i don't want to use any other data structures other than arrays but never mind will work on it

        // nice method but aahhh
        // int arr1 = 0;

        // int arr2 = 0;

        // while(arr1<array1.length && arr2<array2.length){

        // if(array1[arr1]<array2[arr2]){
        // union[unionCounter] = array1[arr1];
        // unionCounter++;
        // arr1++;
        // union[unionCounter] = array2[arr2];
        // arr2++;
        // unionCounter++;
        // }

        // else if (array2[arr2] < array1[arr1]) {
        // union[unionCounter] = array2[arr2];
        // arr2++;
        // unionCounter++;
        // union[unionCounter] = array1[arr1];
        // arr1++;
        // unionCounter++;
        // }

        // else if (array1[arr1] == array2[arr2]) {
        // union[unionCounter] = array1[arr1];
        // arr1++;
        // arr2++;
        // unionCounter++;
        // }

        // }

        
        for (int i = 0; i < array1.length; i++)
        union[i] = array1[i];
        
        int c = 0;
        for (int j = array1.length; j < union.length; j++) {
            union[j] = array2[c];
            c++;
            
        }
        
        // have to implement remove duplicates which currently i can't aaah

        // for (int i = 0; i < union.length-1; i++){
        // for (int j = 0; j < union.length-i-1; j++)
        // if (union[j] > union[j+1])
        // {
        // // swap arr[j+1] and arr[j]
        // int temp = union[j];
        // union[j] = union[j+1];
        // union[j+1] = temp;
        // }
        // }

        HashSet unionHash = new HashSet<>();

        for (int i = 0; i < union.length; i++)
            unionHash.add(union[i]);

        System.out.println(unionHash);

        System.out.println(Arrays.toString(intersection));

    }

    public static void main(String[] args) {
        int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int b[] = { 2, 4, 6, 8 };

        UnionAndIntersection(a, b);
    }
}