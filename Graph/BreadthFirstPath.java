import edu.princeton.cs.algs4.Queue;
import edu.princeton.cs.algs4.Stack;

/**
 * Created by LiuMingyu on 7/3/17.
 */

//  To find a shortest path from s to v, we start at s by following two edges and so forth.
//  - Take the next vertex v from the queue and mark it.
//  - Put onto the queue all unmarked vertices that are adjacent to v.

public class BreadthFirstPath {

    private boolean[] marked;
    private int[] edgeTo;
    private final int s;

    public BreadthFirstPath(Graph G, int s) {
        marked = new boolean[G.V()];    // Is a shortest path to this vertex known?
        edgeTo = new int[G.V()];    // last vertex on known path to this vertex
        this.s = s;
        bfs(G,s);
    }

    private void bfs(Graph G, int s) {
        Queue<Integer> queue = new Queue<Integer>();
        marked[s] = true;   // Mark the source
        queue.enqueue(s);   // Put the source on the queue
        while (!queue.isEmpty()) {  // DO until queue is empty
            int v = queue.dequeue();    // retrieve the next vertex from queue
            for (int w : G.adj(v)) {
                if (!marked[w]) {   // For every unmarked adjacent vertex, save last edge on a shortest path, mark it
                    edgeTo[w] = v;  // because path is known and add it to the queue (to search later)
                    marked[w] = true;
                    queue.enqueue(w);
                }
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
