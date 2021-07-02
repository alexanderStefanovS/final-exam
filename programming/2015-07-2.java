
class Node {

    int value;
    Node[] children;

    Node(int value) {
        this.value = value;
        children = new Node[0];
    }

    public void addNode(Node node) {
        int length = children != null ? children.length + 1: 1;

        Node[] tmp = children;
        children = new Node[length];
        for (int i = 0; i < length - 1; i++) {
            children[i] = tmp[i];
        }
        children[length - 1] = node;
    }

    public void removeChild(Node node) {

        Node[] tmp = children;
        children = new Node[children.length - 1];

        int idx = 0;
        for (int i = 0; i < tmp.length; i++) {
            if (tmp[i] == node) {
                continue;
            }
            children[idx] = tmp[i];
            idx++;
        }

    }

}

class Main {

    public static void dfs(Node root) {
        System.out.print(root.value + " ");
        for (int i = 0; i < root.children.length; i++) {
            dfs(root.children[i]);
        }
    }

    public static boolean member(Node root, int x) {

        System.out.println(root.value);

        if (root.value == x) {
            return true;
        }

        boolean isPresent = false;

        for (int i = 0; i < root.children.length; i++) {
            isPresent = isPresent || member(root.children[i], x);
        }

        return isPresent;
    }

    public static void filteredOdd(Node root) {
        for (int i = 0; i < root.children.length; i++) {
            if (root.children[i].value % 2 != 0) {
                root.removeChild(root.children[i]);
            } else {
                filteredOdd(root.children[i]);
            }
        }
    }

    public static void main(String[] args) {

        Node node4 = new Node(4);
        Node node5 = new Node(5);
        Node node6 = new Node(6);

        Node node2 = new Node(2);
        Node node3 = new Node(3);

        node3.addNode(node4);
        node3.addNode(node5);
        node3.addNode(node6);

        Node node8 = new Node(8);

        node8.addNode(node2);
        node8.addNode(node3);

        boolean isPresent = member(node8, 2);

        System.out.println(isPresent);

        dfs(node8);
        System.out.println("\n");

        filteredOdd(node8);
        dfs(node8);

    }


}
