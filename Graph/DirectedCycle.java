import edu.princeton.cs.algs4.Stack;

/**
 * Created by LiuMingyu on 8/3/17.
 * The idea here is: if we ever find A DIRECTED EDGE v -> w to a vertex w that is on that stack,
 * we have found a cycle and the graph is not acyclic.
 */
public class DirectedCycle {

    private boolean[] marked;
    private int[] edgeTo;
    private Stack<Integer> cycle;   // Vertices on a cycle (if one exists)
    private boolean[] onStack;  // Vertices on recursive call (i.e. dfs()) stack

    public DirectedCycle(Digraph G) {
        onStack = new boolean[G.V()];
        edgeTo = new int[G.V()];
        marked = new boolean[G.V()];
        for (int v = 0; v < G.V(); v++) {
            if (!marked[v]) dfs(G,v);
        }
    }


    private void dfs(Digraph G, int v) {
        onStack[v] = true;
        marked[v] = true;
        for (int w : G.adj(v)) {
            if (this.hasCycle()) return;    // We only need to find one
            else if (!marked[w]) { edgeTo[w] = v; dfs(G, w); }
            else if (onStack[w]) {   // We find a cycle!
                cycle = new Stack<Integer>();
                for (int x = v; x != w; x = edgeTo[x]) {
                    cycle.push(x);
                }
                cycle.push(w);
                cycle.push(v);
            }
        }
        onStack[v] = false; // Exit this recursive call
    }

    public boolean hasCycle() { return cycle != null; }

    public Iterable<Integer> cycle() { return cycle; }
}
