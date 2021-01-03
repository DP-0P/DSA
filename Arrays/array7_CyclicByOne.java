public class array7_CyclicByOne {
    public static <E> E[] CyclicByOne(E[] array){
        E last = array[array.length-1];
        for(int i=array.length-1; i>0; i--)
        array[i] = array[i-1];
        array[0] = last;
        return array;
    }
}
