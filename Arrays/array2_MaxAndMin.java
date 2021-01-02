import java.util.Arrays;

public class array2_MaxAndMin {
    public static void MaxMin(int[] array){
        // Arrays.sort(array);
        // System.out.println("Largest Element "+array[array.length-1]);
        // System.out.println("Smallest Element "+array[0]);
        int max=array[0],min=array[0];
        for(int i=0;i<array.length;i++){
            if(array[i]>max)
            max=array[i];
            else if(array[i]<min)
            min=array[i];
        }
        System.out.println("Largest Element "+max);
        System.out.println("Smallest Element "+min);
    }
}
