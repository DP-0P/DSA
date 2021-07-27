public class testll {
    public static void main(String[] args) {
        MyLinkedList<Integer> ob = new MyLinkedList<>();
        ob.add(9);
        ob.add(89);
        ob.add(100);
        ob.add(89);
        ob.add(9);
        ob.print();
        ob.lastIndexOf(9);
        System.out.println("working");
        // ob.deleteAll(89);
        // ob.contains(3);
        // ob.Reverse();
        // ob.print();
        // ob.Search(100);
        // ob.delete(99);
        // ob.print();
        // ob.Search(100);
        // ob.print();
        // ob.delete(14);
        // ob.Search(34);
        // ob.Search(14);
    }
}
