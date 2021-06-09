//to print powerSet of a string
public class recursion6 {
    public static void main(String[] args) {
        powerSet("abc", 0, "");
    }
    public static void powerSet(String s , int i , String current){
        if(i== s.length()){
            System.out.println(current);
            return;
        }
        powerSet(s, i+1, current+s.charAt(i));
        powerSet(s,i+1,current);
    }
}
