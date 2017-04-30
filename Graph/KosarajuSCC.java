import edu.princeton.cs.algs4.MaxPQ;

import java.util.Arrays;

/**
 * Created by LiuMingyu on 17/3/17.
 */
public class KosarajuSCC {

    private boolean[] marked;
    private int[] id;
    private int count;  // number of strong components
    private MaxPQ<Integer> topFive; // for Assignment 1

    public KosarajuSCC(Digraph G) {
        marked = new boolean[G.V()];
        id = new int[G.V()];
        DepthFirstOrder order = new DepthFirstOrder((G.reverse()));
        for (int s : order.reversePost()) {
            if (!marked[s]) { dfs(G, s); count++; }
        }
    }

    private void dfs(Digraph G, int v) {
        marked[v] = true;
        id[v] = count;  // 执行一次DFS能到达的地方有着相同的count，即id[v]相同
        // 在Stanford的Algorithms中被称为同一个Leader.
        for (int w : G.adj(v)) {
            if (!marked[w]) dfs(G, w);
        }
    }

    public boolean stronglyConnected(int v, int w) { return id[v] == id[w]; }

    public int[] topFive(Digraph G) {   // for Assignment 1

        int[] countArray = new int[count + 1];
        for (int i = 0; i <= count; i++) countArray[i] = 0;

        for (int j = 0; j < G.V(); j++) {
            countArray[id[j]] += 1;
        }

        int[] topFiveArray = new int[5];

        Arrays.sort(countArray);

        for (int k = 0; k < 5; k++) {
            try {
                topFiveArray[k] = countArray[k];
            }
            catch (IndexOutOfBoundsException e) {
                break;
            }
        }

        return topFiveArray;
    }
}
