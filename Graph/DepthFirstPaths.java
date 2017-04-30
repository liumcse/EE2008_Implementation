import edu.princeton.cs.algs4.Stack;

/**
 * Created by LiuMingyu on 7/3/17.
 */

//    dfs(node current) {
//            mark current as visited;
//            visit all of current's unvisited neighbors by calling dfs(neighbor)
//            }
//

public class DepthFirstPaths {

    private boolean[] marked;
    private int[] edgeTo;
    private final int s;

    public DepthFirstPaths(Graph G, int s) {
        marked = new boolean[G.V()];
        edgeTo = new int[G.V()];
        this.s = s;
        dfs(G, s);
    }

    private void dfs(Graph G, int v) {
        marked[v] = true;
        for (int w: G.adj(v)) {
            if (!marked[w]) {
                edgeTo[w] = v;
                dfs(G, w); // search the adjacenct vertices recursively
            }
        }
    }

    public boolean hasPathTo(int v) { return marked[v]; }

    public Iterable<Integer> pathTo(int v) {
        if (!hasPathTo(v)) return null;
        Stack<Integer> path = new Stack<Integer>();
        for (int x = v; x != s; x = edgeTo[x]) { path.push(x); }
        path.push(s);
        return path;
    }

    public static void main(String[] args) {
        // Create a graph with 6 vertices:
        Graph a = new Graph(6);

        // Add 8 edges
        a.addEdge(0, 2);
        a.addEdge(0, 1);
        a.addEdge(0, 5);
        a.addEdge(1, 2);
        a.addEdge(2, 3);
        a.addEdge(2, 4);
        a.addEdge(3, 4);
        a.addEdge(3, 5);

        DepthFirstPaths test = new DepthFirstPaths(a, 0);
        for (int element : test.pathTo(4)) {
            System.out.println(element);
        }

    }
}
