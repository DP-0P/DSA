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
            System.out.print(temp.data+" ");
            temp = temp.next;
        }
    }

    void deleteFirst(D data) {
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

    // corner case testing
    void deleteAll(D data) {
        Node<D> previous = null;
        Node<D> current = head;
        while (current != null) {
            while (current.data == data) {
                if (current.next == null) {
                    previous.next = null;
                    return;
                } else if (current.next != null) {
                    current.data = current.next.data;
                    current.next = current.next.next;
                }
            }
            previous = current;
            current = current.next;
        }
    }

    void Search(D data) {
        Node<D> temp = head;
        int search = 0;
        while (temp != null) {
            if (temp.data == data) {
                System.out.println(search);
                return;
            } else
                search++;
            temp = temp.next;
        }
    }

    void Reverse() {
        Node<D> previous = null;
        Node<D> current = head;
        Node<D> next;
        while (current != null) {
            next = current.next;
            current.next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }

    // deletelast
    // insertion
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
