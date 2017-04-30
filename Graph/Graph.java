import edu.princeton.cs.algs4.Bag;

/**
 * Created by LiuMingyu on 7/3/17.
 */

//  Basic idea (Psudocode) of this graph representation:
//  class Graph {
//      INT numberOfVertices;
//      LIST adjancency;    // Here, we use Bag
//  }

public class Graph {

    private final int V;    // number of vertices
    private int E;  // number of edges
    private Bag<Integer>[] adj; // adjacency lists

    public Graph(int V) {   // Create a graph with V vertices
        this.V = V;
        this.E = 0;
        adj = (Bag<Integer>[]) new Bag[V];
        for (int v = 0; v < V; v++) { adj[v] = new Bag<Integer>(); }
    }

    public int V() { return V; }
    public int E() { return E; }

    public void addEdge(int v, int w) {
        adj[v].add(w);
        adj[w].add(v);
        E++;
    }

    public Iterable<Integer> adj(int v) { return adj[v]; }

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

        // Iterate vertices adjacent to 5
        for (int element : a.adj(5)) {
            System.out.print(element + " ");
        }
    }
}