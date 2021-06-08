//printing name n times using recursion
public class recursion1 {
    public static void main(String[] args) {
        recuName("Deepak",5);
    }
    public static void recuName(String name , int n){
        if(n==0)
        return;

        else{
            System.out.println(name);
            recuName(name, n-1);
        }
    }
}
