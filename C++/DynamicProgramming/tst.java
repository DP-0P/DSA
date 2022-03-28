import java.util.Scanner;
class tst{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        System.out.println(useful(n, k));
        sc.close();
    }
    public static int digSum(int n){
        int sum = 0;
        while (n != 0) {
            sum = sum + n % 10;
            n = n / 10;
        }
        return sum;
    }

    public static long useful(int n,int k){
        long M = 1000000007;
        int sum = 0;
        int i=0,j=1;
        while(i!=n){
        if(digSum(j)<=k){
            sum += j;
            i++;
            j++;
        }
        else
            j++;
    }
    return sum%M;
    }
}