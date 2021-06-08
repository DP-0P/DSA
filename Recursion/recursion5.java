//to check palindrome of a string
public class recursion5 {
    public static void main(String[] args) {
        String name = "abba";
        System.out.println(palindrome(name, 0 , name.length()-1));
    }
    public static boolean palindrome(String name , int l , int r){

        if(l>=r)
        return true;

        else if(name.charAt(l) != name.charAt(r))
        return false;

        return palindrome(name, l+1, r-1);
    }
}