import java.util.Arrays;

public class cyclicByOne {
    public static void CyclicByOne(int array[]){
        int last = array[array.length-1];
        for(int i=array.length-1; i>0; i--)
        array[i] = array[i-1];
        array[0] = last;
        System.out.println(Arrays.toString(array));
    }
}
