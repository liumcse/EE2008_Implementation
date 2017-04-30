/**
 * Created by LiuMingyu on 7/3/17.
 * This is an application of depth-first search, which is to find the connected components of a graph.
 * 'CC' refers to Connected Components
 */
public class CC {

    private boolean[] marked;
    private int[] id;
    private int count;

    public CC(Graph G) {
        marked = new boolean[G.V()];
        id = new int[G.V()];
        for (int s = 0; s < G.V(); s++) {
            if (!marked[s]) {
                dfs(G, s);
                count++;
            }
        }
    }

    private void dfs(Graph G, int v) {
        marked[v] = true;
        id[v] = count;  // id[v] is set to i if v is in the ith connected component processed
        for (int w : G.adj(v)) {
            if (!marked[w]) { dfs(G, w); }
        }
    }

    public boolean connected(int v, int w) { return id[v] == id[w]; }
    public int id(int v) { return id[v]; }
    public int count() { return count; }

    public static void main(String[] args) {
        //  Create a graph of 13 vertices
        Graph test = new Graph(13);
        test.addEdge(0, 6);
        test.addEdge(0, 2);
        test.addEdge(0, 1);
        test.addEdge(0, 5);
        test.addEdge(3, 5);
        test.addEdge(3, 4);
        test.addEdge(4, 5);
        test.addEdge(4, 6);
        test.addEdge(7, 8);
        test.addEdge(9, 11);
        test.addEdge(9, 10);
        test.addEdge(9, 12);

        CC test_CC = new CC(test);
        System.out.println(test_CC.connected(0, 6));
    }
}
