public class palindrome {
    public static void main(String[] args) {
        palindrome("madam");
    }
    public static void palindrome(String s){
        String rev = "";
        for(int i=s.length()-1;i>=0;--i)
            rev+=s.charAt(i);
        
        if(s.equalsIgnoreCase(rev))
            System.out.println("Entered string is palindrome");
        else
            System.out.println("Entered string is not palindrome");
    }
}
