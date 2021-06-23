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

    void addFirst(D data) {
        Node<D> add = new Node<D>(data);
        if (head == null) {
            head = add;
            return;
        }
        Node<D> temp = add;
        temp.next = head;
        head = add;
    }

    void addAt(int index,D data) {
        Node<D> add = new Node<D>(data);
        Node<D> temp = head;
        index--;
        if(temp!=null)
            for(int i=0;i<index && temp.next!=null;i++)
                temp = temp.next;
        add.next = temp.next;
        temp.next = add;
    }

    void print() {
        Node<D> temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
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

    void contains(D data) {
        Node<D> temp = head;
        while (temp != null) {
            if (temp.data == data) {
                System.out.println("true");
                return;
            }
            temp = temp.next;
        }
        System.out.println("false");
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

    void Clear() {
        Node<D> temp = head;
        while (temp != null) {
            head = null;
            temp.next = null;
            temp = temp.next;
        }
    }

    void Size() {
        Node<D> temp = head;
        int size = 0;
        while (temp != null) {
            size++;
            temp = temp.next;
        }
        System.out.println(size);
    }

    void deleteLast(){
        if(head==null)
            return;
        if(head.next==null)
            return;
        Node<D> second = head;
        while(second.next.next != null)
            second = second.next;
        second.next = null;
    }

    // lastIndexOf
    void lastIndexOf(D data){
        Node<D> current= head;
        int lastIndex = 0;
        int count =0;
        while(current != null){
            if(current.data == data)
                lastIndex = count;  
        count++;
        current = current.next;
        }
        System.out.println(lastIndex);
    }
}
