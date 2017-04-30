import edu.princeton.cs.algs4.Queue;
import edu.princeton.cs.algs4.Stack;

/**
 * Created by LiuMingyu on 8/3/17.
 * Here we implement three types of order: preorder, postorder and reverse postorder
 */
public class DepthFirstOrder {

    private boolean[] marked;
    private Queue<Integer> pre; // vertices in preorder
    private Queue<Integer> post;    // vertices in postorder
    private Stack<Integer> reversePost; // vertices in reverse postorder

    public DepthFirstOrder(Digraph G) {
        pre = new Queue<>();
        post = new Queue<>();
        reversePost = new Stack<>();
        marked = new boolean[G.V()];

        for (int v = 0; v < G.V(); v++) {
            if (!marked[v]) dfs(G,v);   // call DFS
        }
    }

    private void dfs(Digraph G, int v) {
        pre.enqueue(v);
        marked[v] = true;
        for (int w : G.adj(v)) {
            if (!marked[w]) dfs(G,w);
        }
        post.enqueue(v);
        reversePost.push(v);
    }

    public Iterable<Integer> pre() { return pre; }
    public Iterable<Integer> post() { return post; }
    public Iterable<Integer> reversePost() { return reversePost; }

    public static void main(String[] args) {
        // Create a digraph
//        Digraph g = new Digraph(13);
//        g.addEdge(0, 1);
//        g.addEdge(0, 5);
//        g.addEdge(0, 6);
//        g.addEdge(2, 0);
//        g.addEdge(2, 3);
//        g.addEdge(3, 5);
//        g.addEdge(5, 4);
//        g.addEdge(6, 4);
//        g.addEdge(6, 9);
//        g.addEdge(7, 6);
//        g.addEdge(8, 7);
//        g.addEdge(9, 10);
//        g.addEdge(9, 11);
//        g.addEdge(9, 12);
//        g.addEdge(11, 12);
        Digraph g = new Digraph(10);
        // add edges
        g.addEdge(1, 4);
        g.addEdge(2, 8);
        g.addEdge(3, 6);
        g.addEdge(4, 7);
        g.addEdge(5, 2);
        g.addEdge(6, 9);
        g.addEdge(7, 1);
        g.addEdge(8, 5);
        g.addEdge(8, 6);
        g.addEdge(9, 7);
        g.addEdge(9, 3);

        System.out.print("reversePost:\t");
        for (int element : new DepthFirstOrder(g.reverse()).reversePost()) {
            System.out.print(element + "\t");
        }
        System.out.println();
        System.out.print("Preorder:\t\t");
        for (int element : new DepthFirstOrder(g).pre()) {
            System.out.print(element + "\t");
        }
        System.out.println();
        System.out.print("Postorder:\t\t");
        for (int element : new DepthFirstOrder(g).post()) {
            System.out.print(element + "\t");
        }
    }
}
