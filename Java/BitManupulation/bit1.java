public class bit1 {
    public static void main(String[] args) {
        countSet(6);
    }
    public static void countSet(int n){
        int c=0;
        while(n>0){
            c+=n&1;
            n>>=1;
        }
        System.out.println(c);
    }
}
