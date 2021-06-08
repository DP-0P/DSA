class test {
    public static void main(String[] args) {
        int n = 69;
        int c=0;
        while(n>0){
            n = n&(n-1);
            c++;
        }
        System.out.println(c);
}}