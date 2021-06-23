public class MyLinkedList<D> {

    class Node<D> {
        D data;
        Node<D> next;

        Node(D data) {
            this.data = data;
            next = null;
        }
    }

    Node<D> head;

    void add(D data) {
        Node<D> add = new Node<D>(data);
        if (head == null) {
            head = add;
            return;
        }
        Node<D> temp = head;
        while (temp.next != null)
            temp = temp.next;
        temp.next = add;
    }

    void print() {
        Node<D> temp = head;
        while (temp != null) {
            System.out.println(temp.data);
            temp = temp.next;
        }
    }

    void delete(D data) {
        Node<D> previous = null;
        Node<D> current = head;
        while (current != null) {
            if (current.data == data) {
                if (current.next == null) {
                    previous.next = null;
                    return;
                } else if (current.next != null) {
                    current.data = current.next.data;
                    current.next = current.next.next;
                    return;
                }
            }
            previous = current;
            current = current.next;
        }
    }

    void Search(D data){

        Node<D> temp = head;
        int search=-1;
        while(temp != null){
            int i=0;
            if(temp.data == data){
                search = i;
                return;
            }
            temp = temp.next;
        }
        System.out.println(search);
    }
    // search
    // deleteAll
    // deletefirst
    // deletelast
    // insertion
    // reverse
    // append
    // addFirst
    // addLast
    // clone
    // clear
    // contains
    // getIndex
    // indexOf
    // lastIndexOf
    // peekfirst
    // peekLast
    // size
    // toArray
}
