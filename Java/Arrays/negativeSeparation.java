public class negativeSeparation {
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
}
