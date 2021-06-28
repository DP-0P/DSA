public class ReverseLinkedList {
    static Node head;

    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            next = null;
        }
    }

    void reverseIterative() {
        Node previous = null;
        Node current = head;
        Node next = null;

        while (current != null) {
            next = current.next;
            current.next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }

    // Time Complexity: O(n)
    // Space Complexity: O(1)

    Node reverseRecursive(Node head) {
        if (head == null || head.next == null)
            return head;

        Node rev = reverseRecursive(head.next);
        head.next.next = head;
        head.next = null;
        return rev;
    }
    // Time Complexity: O(n)
    // Space Complexity: O(1)

    void print() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }
    public static void main(String[] args) {
        ReverseLinkedList ob = new ReverseLinkedList();

        ob.head = new Node(45);
        ob.head.next = new Node(5);
        ob.head.next.next = new Node(65);
        ob.head.next.next.next = new Node(75);
        ob.head.next.next.next.next = new Node(95);

        ob.print();
        head = ob.reverseRecursive(head);
        ob.print();
    }
}
