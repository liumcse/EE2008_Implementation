/**
 * Created by LiuMingyu on 8/3/17.
 * Compare to the undirected graph DPS, we add a second constructor here which takes a list of vertices
 * This constructor support Multiple-source Reachability, as in this query form: is there a directed path from
 * any vertex in the set to a given target vertex v? (迷宫里，当前的n个路口中有存在一个能到达终点吗？）
 */
public class DirectedDFS {
    
    private boolean[] marked;
    
    public DirectedDFS(Digraph G, int s) {
        marked = new boolean[G.V()];
        dfs(G, s);
    }
    
    public DirectedDFS(Digraph G, Iterable<Integer> sources) {
        marked = new boolean[G.V()];
        for (int s : sources) {
            if (!marked[s]) dfs(G, s);
        }
    }
    
    private void dfs(Digraph G, int v) {
        marked[v] = true;
        for (int w : G.adj(v)) {
            if (!marked[w]) dfs(G, w);
        }
    }
    
    public boolean marked(int v) { return marked[v]; }
    
    public static void main(String[] args) {
        // Create a digraph g
        Digraph g = new Digraph(13);
        g.addEdge(4, 2);
        g.addEdge(2, 3);
        g.addEdge(3, 2);
        g.addEdge(6, 0);
        g.addEdge(0, 1);
        g.addEdge(2, 0);
        g.addEdge(11, 12);
        g.addEdge(12, 9);
        g.addEdge(9, 10);
        g.addEdge(9, 11);
        g.addEdge(8, 9);
        g.addEdge(10, 12);
        g.addEdge(11, 4);
        g.addEdge(4, 3);
        g.addEdge(3, 5);
        g.addEdge(7, 8);
        g.addEdge(8, 7);
        g.addEdge(5, 4);
        g.addEdge(0, 5);
        g.addEdge(6, 4);
        g.addEdge(6, 9);
        g.addEdge(7, 6);

        DirectedDFS reachable = new DirectedDFS(g, 0);
        for (int v = 0; v < g.V(); v++) {
            if (reachable.marked(v)) System.out.print(v + " ");
        }
    }
}
