import java.util.Arrays;

public class array5 {
    public static int[] partiton(int a[]){
        int c=0;
        for(int i=0;i<a.length;i++){
            if(a[i]<0){
                int temp = a[i];
                a[i] = a[c];
                a[c] = temp;
                c++;
            }
        }
        return a;
    }
    public static void main(String[] args) {
        int a[] = {5,0,-3,5,7,8,-8,-1};
        System.out.println(Arrays.toString(partiton(a)));
    }
}
