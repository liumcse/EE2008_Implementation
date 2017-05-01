/**
 * Created by LiuMingyu on 6/3/17.
 */
public class Sorting {
    // My attempt
    private static void merge(int[] a, int lo, int mid, int hi) {
        int i = lo;
        int j = mid + 1;
        int aux[] = new int[hi + 1];
        for (int k = lo; k <= hi; k++) aux[k] = a[k];
        int k = lo;
        while ((i <= mid) && (j <= hi)) {
            if (aux[i] < aux[j]) a[k++] = aux[i++];
            else a[k++] = aux[j++];
        }
        while (i <= mid) a[k++] = aux[i++];
        while (j <= hi) a[k++] = aux[j++];
    }

    // A better merge learned from Algorithms 4th.
    private static void betterMerge(int[] a, int lo, int mid, int hi) {
        int i = lo;
        int j = mid + 1;
        int aux[] = new int[hi + 1];
        for (int k = lo; k <= hi; k++) aux[k] = a[k];
        for (int k = lo; k <= hi; k++) {
            if (i > mid) a[k] = aux[j++];
            else if (j > hi) a[k] = aux[i++];
            else if (aux[i] < aux[j]) a[k] = aux[i++];
            else a[k] = aux[j++];
        }
    }

    private static void mergesort(int a[], int lo, int hi) {
        if (lo == hi) return;
        int mid = (lo + hi) / 2;
        mergesort(a, lo, mid);
        mergesort(a, mid + 1, hi);
        merge(a, lo, mid, hi);
    }

    public static void main(String[] args) {
        // mergesort test
        int[] s = {132, 12, 2, 301, 69, 7, 8312, 998};
        Sorting.mergesort(s, 0, 7);
        for (int i = 0; i < s.length; i++) {
            System.out.println(s[i]);
        }

        // merge test
        int[] a = {1, 12, 21, 30, 6, 7, 8, 9};
        Sorting.merge(a, 0, 3, 7);
        for (int i = 0; i < a.length; i++) System.out.print(a[i] + " ");
        System.out.println();

        // betterMerge test
        int[] b = {1, 12, 21, 30, 6, 7, 8, 9};
        Sorting.betterMerge(b, 0, 3, 7);
        for (int i = 0; i < b.length; i++) System.out.print(b[i] + " ");
    }
}
