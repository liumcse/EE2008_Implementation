/**
 * Created by LiuMingyu on 2/4/17.
 * This is an implementaion using a MaxHeap structure
 * Note that pq[0] is unused
 */
public class PriorityQueue<Key extends Comparable<Key>> {
    private Key pq[];
    private final int max;
    private int N = 0;

    public PriorityQueue(int max) {
        this.max = max + 1;
        this.pq = (Key[]) new Comparable[this.max];
    }

    public void insert(Key v) {
        if (N == max) throw new IndexOutOfBoundsException("Exceed maximum!");
        pq[N++] = v;
        swim(N);
    }

    public Key max() {
        return pq[1];
    }

    public Key delMax() {
        if (isEmpty()) return null;
        Key max = pq[1];
        exch(1, N--);
        pq[N+1] = null;
        sink(1);
        return max;
    }

    public int size() { return N; }
    public boolean isEmpty() { return N == 0; }

    private void swim(int k) {
        while (k/2 != 0) {
            if (less(k/2,k)) exch(k/2, k);
            k = k/2;
        }
    }

    private void sink(int k) {
        while (2*k <= N) {
            int j = 2*k;
            if (j < N && less(j, j+1)) j++;   // 注意要查 j < max 喔
            if (!less(k, j)) break;
            exch(k,j);
            k = j;
        }
    }

    private void exch(int i, int j) {
        Key temp = pq[i];
        pq[i] = pq[j];
        pq[j] = temp;
    }

    private boolean less(int i, int j) {
        return pq[i].compareTo(pq[j]) < 0;
    }
}
