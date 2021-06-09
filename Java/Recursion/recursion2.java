//find sum of n natural numbers
public class recursion2 {
    public static void main(String[] args) {
      System.out.println(recuSum(5));
    }
    public static int recuSum(int n){
        if(n==0)
        return 0;

        else if(n==1)
        return 1;

        else
        return recuSum(n-1) + n;
    }
}