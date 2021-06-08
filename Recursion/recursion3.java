//find a^b
public class recursion3 {
    public static void main(String[] args) {
        System.out.println(recuPower(2, 3));        
    }
    public static int recuPower(int base, int power){
        if(power==1)
        return base;

        else if(power==0)
        return 1;

        else
        return base * recuPower(base, power-1);
    }
}
