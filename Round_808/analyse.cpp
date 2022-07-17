import java.util.*;
// import java.util.concurrent.CountDownLatch;
import java.util.concurrent.atomic.AtomicBoolean;

import javax.print.attribute.HashAttributeSet;
import javax.sound.sampled.BooleanControl;
import javax.swing.event.ChangeEvent;
import javax.swing.text.Position;
import javax.swing.text.StyleConstants;
import javax.xml.validation.Validator;

// import javax.lang.model.element.QualifiedNameable;
// import javax.swing.ViewportLayout;
// import javax.swing.plaf.basic.BasicTreeUI.TreeCancelEditingAction;
// import javax.swing.plaf.metal.MetalComboBoxUI.MetalPropertyChangeListener;
// import javax.swing.text.html.HTMLDocument.HTMLReader.CharacterAction;

// import org.w3c.dom.Node;

import java.lang.*;
import java.math.BigInteger;
import java.net.NetworkInterface;
import java.text.SimpleDateFormat;
import java.beans.beancontext.BeanContext;
// import java.net.CookieHandler;
// import java.security.SecureRandomParameters;
// import java.security.cert.CollectionCertStoreParameters;
// import java.text.BreakIterator;
import java.io.*;

@SuppressWarnings("unchecked")
public class Main implements Runnable{
    static FastReader in;
    static PrintWriter out;

    static int bit(long n) {
        return (n == 0) ? 0 : (1 + bit(n & (n - 1)));
    }

    static void p(Object o) {
        out.print(o);
    }

    static void pn(Object o) {
        out.println(o);
    }

    static void pni(Object o) {
        out.println(o);
        out.flush();
    }

    static String n() throws Exception {
        return in.next();
    }

    static String nln() throws Exception {
        return in.nextLine();
    }

    static int ni() throws Exception {
        return Integer.parseInt(in.next());
    }

    static long nl() throws Exception {
        return Long.parseLong(in.next());
    }

    static double nd() throws Exception {
        return Double.parseDouble(in.next());
    }

    static class FastReader {
        static BufferedReader br;
        static StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastReader(String s) throws Exception {
            br = new BufferedReader(new FileReader(s));
        }

        String next() throws Exception {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new Exception(e.toString());
                }
            }
            return st.nextToken();
        }

        String nextLine() throws Exception {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                throw new Exception(e.toString());
            }
            return str;
        }
    }

    static long power(long a, long b) {
        if (a == 0L)
            return 0L;
        if (b == 0)
            return 1;
        long val = power(a, b / 2);
        val = val * val;
        if ((b % 2) != 0)
            val = val * a;
        return val;
    }

    static long power(long a, long b, long mod) {
        if (a == 0L)
            return 0L;
        if (b == 0)
            return 1;
        long val = power(a, b / 2L, mod) % mod;
        val = (val * val) % mod;
        if ((b % 2) != 0)
            val = (val * a) % mod;
        return val;
    }

    static ArrayList<Long> prime_factors(long n) {
        ArrayList<Long> ans = new ArrayList<Long>();
        while (n % 2 == 0) {
            ans.add(2L);
            n /= 2L;
        }
        for (long i = 3; i <= Math.sqrt(n); i++) {
            while (n % i == 0) {
                ans.add(i);
                n /= i;
            }
        }
        if (n > 2) {
            ans.add(n);
        }
        return ans;
    }

    static void sort(ArrayList<Long> a) {
        Collections.sort(a);
    }

    static void reverse_sort(ArrayList<Long> a) {
        Collections.sort(a, Collections.reverseOrder());
    }

    static void swap(long[] a, int i, int j) {
        long temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    static void swap(List<Long> a, int i, int j) {
        long temp = a.get(i);
        a.set(j, a.get(i));
        a.set(j, temp);
    }

    static void sieve(boolean[] prime) {
        int n = prime.length - 1;
        Arrays.fill(prime, true);
        for (int i = 2; i * i <= n; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
    }

    static long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    /*
     * ----------------------------------------------------Sorting------------------
     * ------------------------------------------------
     */

    public static void sort(long[] arr, int l, int r) {
        if (l >= r)
            return;
        int mid = (l + r) / 2;
        sort(arr, l, mid);
        sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }

    public static void sort(int[] arr, int l, int r) {
        if (l >= r)
            return;
        int mid = (l + r) / 2;
        sort(arr, l, mid);
        sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }

    static void merge(int[] arr, int l, int mid, int r) {
        int[] left = new int[mid - l + 1];
        int[] right = new int[r - mid];
        for (int i = l; i <= mid; i++) {
            left[i - l] = arr[i];
        }
        for (int i = mid + 1; i <= r; i++) {
            right[i - (mid + 1)] = arr[i];
        }
        int left_start = 0;
        int right_start = 0;
        int left_length = mid - l + 1;
        int right_length = r - mid;
        int temp = l;
        while (left_start < left_length && right_start < right_length) {
            if (left[left_start] < right[right_start]) {
                arr[temp] = left[left_start++];
            } else {
                arr[temp] = right[right_start++];
            }
            temp++;
        }
        while (left_start < left_length) {
            arr[temp++] = left[left_start++];
        }
        while (right_start < right_length) {
            arr[temp++] = right[right_start++];
        }
    }

    static void merge(long[] arr, int l, int mid, int r) {
        long[] left = new long[mid - l + 1];
        long[] right = new long[r - mid];
        for (int i = l; i <= mid; i++) {
            left[i - l] = arr[i];
        }
        for (int i = mid + 1; i <= r; i++) {
            right[i - (mid + 1)] = arr[i];
        }
        int left_start = 0;
        int right_start = 0;
        int left_length = mid - l + 1;
        int right_length = r - mid;
        int temp = l;
        while (left_start < left_length && right_start < right_length) {
            if (left[left_start] < right[right_start]) {
                arr[temp] = left[left_start++];
            } else {
                arr[temp] = right[right_start++];
            }
            temp++;
        }
        while (left_start < left_length) {
            arr[temp++] = left[left_start++];
        }
        while (right_start < right_length) {
            arr[temp++] = right[right_start++];
        }
    }

    static HashMap<Long, Integer> map_prime_factors(long n) {
        HashMap<Long, Integer> map = new HashMap<>();
        while (n % 2 == 0) {
            map.put(2L, map.getOrDefault(2L, 0) + 1);
            n /= 2L;
        }
        for (long i = 3; i <= Math.sqrt(n); i++) {
            while (n % i == 0) {
                map.put(i, map.getOrDefault(i, 0) + 1);
                n /= i;
            }
        }
        if (n > 2) {
            map.put(n, map.getOrDefault(n, 0) + 1);
        }
        return map;
    }

    static List<Long> divisor(long n) {
        List<Long> ans = new ArrayList<>();
        ans.add(1L);
        long count = 0;
        for (long i = 2L; i * i <= n; i++) {
            if (n % i == 0) {
                if (i == n / i)
                    ans.add(i);
                else {
                    ans.add(i);
                }
            }
        }
        return ans;
    }

    // static void smallest_prime_factor(int n) {
    // smallest_prime_factor[1] = 1;
    // for (int i = 2; i <= n; i++) {
    // if (smallest_prime_factor[i] == 0) {
    // smallest_prime_factor[i] = i;
    // for (int j = i * i; j <= n; j += i) {
    // if (smallest_prime_factor[j] == 0) {
    // smallest_prime_factor[j] = i;
    // }
    // }
    // }
    // }
    // }

    // static int[] smallest_prime_factor;
    // static int count = 1;
    // static int[] p = new int[100002];
    // static long[] flat_tree = new long[300002];
    // static int[] in_time = new int[1000002];
    // static int[] out_time = new int[1000002];
    // static long[] subtree_gcd = new long[100002];
    // static int w = 0;
    // static boolean poss = true;

    /*
     * (a^b^c)%mod
     * Using fermats Little theorem
     * x^(mod-1)=1(mod)
     * so b^c can be written as b^c=x*(mod-1)+y
     * then (a^(x*(mod-1)+y))%mod=(a^(x*(mod-1))*a^(y))mod
     * the term (a^(x*(mod-1)))%mod=a^(mod-1)*a^(mod-1)
     * 
     */
    // ---------------------------------------------------Segment_Tree----------------------------------------------------------------//
    // static class comparator implements Comparator<node> {
    // public int compare(node a, node b) {
    // return a.a - b.a > 0 ? 1 : -1;
    // }
    // }

    static class Segment_Tree {
        private long[] segment_tree;

        public Segment_Tree(int n) {
            this.segment_tree = new long[4 * n + 1];
        }

        void build(int index, int left, int right, int[] a) {
            if (left == right) {
                segment_tree[index] = a[left];
                return;
            }
            int mid = (left + right) / 2;
            build(2 * index + 1, left, mid, a);
            build(2 * index + 2, mid + 1, right, a);
            segment_tree[index] = segment_tree[2 * index + 1] + segment_tree[2 * index + 2];
        }

        long query(int index, int left, int right, int l, int r) {
            if (left > right)
                return 0;
            if (left >= l && r >= right) {
                return segment_tree[index];
            }
            if (l > right || left > r)
                return 0;
            int mid = (left + right) / 2;
            return query(2 * index + 1, left, mid, l, r) + query(2 * index + 2, mid + 1, right, l, r);
        }

        void update(int index, int left, int right, int node, int val) {
            if (left == right) {
                segment_tree[index] += val;
                return;
            }
            int mid = (left + right) / 2;
            if (node <= mid)
                update(2 * index + 1, left, mid, node, val);
            else
                update(2 * index + 2, mid + 1, right, node, val);
            segment_tree[index] = segment_tree[2 * index + 1] + segment_tree[2 * index + 2];
        }
    }

    static class min_Segment_Tree {
        private long[] segment_tree;

        public min_Segment_Tree(int n) {
            this.segment_tree = new long[4 * n + 1];
        }

        void build(int index, int left, int right, int[] a) {
            if (left == right) {
                segment_tree[index] = a[left];
                return;
            }
            int mid = (left + right) / 2;
            build(2 * index + 1, left, mid, a);
            build(2 * index + 2, mid + 1, right, a);
            segment_tree[index] = Math.min(segment_tree[2 * index + 1], segment_tree[2 * index + 2]);
        }

        long query(int index, int left, int right, int l, int r) {
            if (left > right)
                return Integer.MAX_VALUE;
            if (left >= l && r >= right) {
                return segment_tree[index];
            }
            if (l > right || left > r)
                return Integer.MAX_VALUE;
            int mid = (left + right) / 2;
            return Math.min(query(2 * index + 1, left, mid, l, r), query(2 * index + 2, mid + 1, right, l, r));
        }
    }

    static class max_Segment_Tree {
        private long[] segment_tree;

        public max_Segment_Tree(int n) {
            this.segment_tree = new long[4 * n + 1];
        }

        void build(int index, int left, int right, int[] a) {
            if (left == right) {
                segment_tree[index] = a[left];
                return;
            }
            int mid = (left + right) / 2;
            build(2 * index + 1, left, mid, a);
            build(2 * index + 2, mid + 1, right, a);
            segment_tree[index] = Math.min(segment_tree[2 * index + 1], segment_tree[2 * index + 2]);
        }

        long query(int index, int left, int right, int l, int r) {
            if (left > right)
                return Integer.MIN_VALUE;
            if (left >= l && r >= right) {
                return segment_tree[index];
            }
            if (l > right || left > r)
                return Integer.MIN_VALUE;
            int mid = (left + right) / 2;
            return Math.max(query(2 * index + 1, left, mid, l, r), query(2 * index + 2, mid + 1, right, l, r));
        }
    }

    // ------------------------------------------------------ DSU
    // --------------------------------------------------------------------//
    static class dsu {
        private int[] parent;
        private int[] rank;
        private int[] size;

        public dsu(int n) {
            this.parent = new int[n + 1];
            this.rank = new int[n + 1];
            this.size = new int[n + 1];
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
                rank[i] = 1;
                size[i] = 1;
            }
        }

        int findParent(int a) {
            if (parent[a] == a)
                return a;
            else
                return parent[a] = findParent(parent[a]);
        }

        void join(int a, int b) {
            int parent_a = findParent(a);
            int parent_b = findParent(b);
            if (parent_a == parent_b)
                return;
            if (rank[parent_a] > rank[parent_b]) {
                parent[parent_b] = parent_a;
                size[parent_a] += size[parent_b];
            } else if (rank[parent_a] < rank[parent_b]) {
                parent[parent_a] = parent_b;
                size[parent_b] += size[parent_a];
            } else {
                parent[parent_a] = parent_b;
                size[parent_b] += size[parent_a];
                rank[parent_b]++;
            }
        }
    }

    // ------------------------------------------------Comparable---------------------------------------------------------------------//
    static class pair implements Comparable<pair> {
        int a;
        int b;
        int dir;

        public pair(int a, int b, int dir) {
            this.a = a;
            this.b = b;
            this.dir = dir;
        }

        public int compareTo(pair p) {
            // if (this.b == Integer.MIN_VALUE || p.b == Integer.MIN_VALUE)
            // return (int) (this.index - p.index);
            return (int) (this.a - p.a);
        }

    }

    static class pair2 implements Comparable<pair2> {
        long a;
        int index;

        public pair2(long a, int index) {
            this.a = a;
            this.index = index;
        }

        public int compareTo(pair2 p) {
            return (int) (this.a - p.a);
        }

    }

    static class node implements Comparable<node>{
        int l;
        int r;

        public node(int l, int r) {
            this.l = l;
            this.r = r;
        }

        public int compareTo(node a){
            if(this.l==a.l)return this.r-a.r;
            return a.l-this.l;
        }
    }

    // static int ans = 0;
    static long ans = 0;
    static int leaf = 0;
    static boolean poss = true;
    static long mod = 1000000007L;
    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { 1, -1, 0, 0 };
    static long[] sub = new long[300001];
    static boolean cycle;
    static int count=0;

    public static void main(String[] args) throws Exception {
        // in = new FastReader();
        // out = new PrintWriter(System.out);
        new Thread(null, new Main(), "Main", 1<<32).start();
        // int tc = ni();
        // while (tc-- > 0) {
        //     int n=ni();
        //     int c=ni();
        //     int q=ni();
        //     String s=n();
        //     int[][] a=new int[c][2];
        //     int length=n;
        //     for(int i=0;i<c;i++){
        //         a[i][0]=ni();
        //         a[i][1]=ni();
        //         length+=a[i][1]-a[i][0]+1;
        //     }
        //     char[] ans=new char[length];
        //     for(int i=0;i<n;i++){
        //         ans[i]=s.charAt(i);
        //     }
        //     int index=n;
        //     for(int i=0;i<c;i++){
        //         for(int j=a[i][0]-1;j<=a[i][1]-1;j++){
        //             ans[index]=ans[j];
        //             index++;
        //         }
        //     }
        //     for(int i=0;i<q;i++){
        //         int l=ni();
        //         pn(ans[l-1]);
        //     }
        //     pn(String.valueOf(ans));
        // }
        // out.flush();
        // out.close();
    }
    public void run(){
        try{

            in = new FastReader();
            out = new PrintWriter(System.out);
        int tc = ni();
        while (tc-- > 0) {
            int n=ni();
            int l=ni();
            int r=ni();
            boolean poss=true;
            for(int i=1;i<=n;i++){
                if(((r/i)*i)<l)poss=false;
            }
            if(!poss){
                pn("NO");
                continue;
            }
            pn("YES");
            for(int i=1;i<=n;i++){
                p(((r/i)*i)+" ");
            }
            pn("");
                

        }
        out.flush();
        out.close();
      }catch(Exception e){

      }
    }
    static int binary_search(int[] a,int val){
        int l=0;
        int r=a.length-1;
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(a[mid]<=val){
                ans=mid;
                l=mid+1;
            }else r=mid-1;
        }
        return ans;
    }

    static int[] longest_common_prefix(String s) {
        int m = s.length();
        int[] lcs = new int[m];
        int len = 0;
        int i = 1;
        lcs[0] = 0;
        while (i < m) {
            if (s.charAt(i) == s.charAt(len)) {
                lcs[i++] = ++len;
            } else {
                if (len == 0) {
                    lcs[i] = 0;
                    i++;
                } else
                    len = lcs[len - 1];
            }
        }
        return lcs;
    }

    static void swap(char[] a, char[] b, int i, int j) {
        char temp = a[i];
        a[i] = b[j];
        b[j] = temp;
    }
    static void factorial(long[] fact, long[] fact_inv, int n, long mod) {
        fact[0] = 1;
        for (int i = 1; i < n; i++) {
            fact[i] = (i * fact[i - 1]) % mod;
        }
        for (int i = 0; i < n; i++) {
            fact_inv[i] = power(fact[i], mod - 2, mod);// (1/x)%m can be calculated by fermat's little theoram which is
                                                       // (x**(m-2))%m when m is prime
        }

        // (a^(b^c))%m is equal to, let res=(b^c)%(m-1) then (a^res)%m
        // https://www.geeksforgeeks.org/find-power-power-mod-prime/?ref=rp
    }

    static void find(int i, int n, int[] row, int[] col, int[] d1, int[] d2) {
        if (i >= n) {
            ans++;
            return;
        }
        for (int j = 0; j < n; j++) {
            if (col[j] == 0 && d1[i - j + n - 1] == 0 && d2[i + j] == 0) {
                col[j] = 1;
                d1[i - j + n - 1] = 1;
                d2[i + j] = 1;
                find(i + 1, n, row, col, d1, d2);
                col[j] = 0;
                d1[i - j + n - 1] = 0;
                d2[i + j] = 0;
            }
        }
    }

    static int answer(int l, int r, int[][] dp) {
        if (l > r)
            return 0;
        if (l == r) {
            dp[l][r] = 1;
            return 1;
        }
        if (dp[l][r] != -1)
            return dp[l][r];
        int val = Integer.MIN_VALUE;
        int mid = l + (r - l) / 2;
        val = 1 + Math.max(answer(l, mid - 1, dp), answer(mid + 1, r, dp));
        return dp[l][r] = val;
    }

    static TreeSet<Integer> ans(int n) {
        TreeSet<Integer> set = new TreeSet<>();
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                set.add(i);
                set.add(n / i);
            }
        }
        set.remove(1);
        return set;
    }

    // static long find(String s, int i, int n, long[] dp) {
    // // pn(i);
    // if (i >= n)
    // return 1L;
    // if (s.charAt(i) == '0')
    // return 0;
    // if (i == n - 1)
    // return 1L;
    // if (dp[i] != -1)
    // return dp[i];
    // if (s.substring(i, i + 2).equals("10") || s.substring(i, i + 2).equals("20"))
    // {
    // return dp[i] = (find(s, i + 2, n, dp)) % mod;
    // }
    // if ((s.charAt(i) == '1' || (s.charAt(i) == '2' && s.charAt(i + 1) - '0' <=
    // 6))
    // && ((i + 2 < n ? (s.charAt(i + 2) != '0' ? true : false) : (i + 2 == n ? true
    // : false)))) {
    // return dp[i] = (find(s, i + 1, n, dp) + find(s, i + 2, n, dp)) % mod;
    // } else
    // return dp[i] = (find(s, i + 1, n, dp)) % mod;

    static void print(int[] a) {
        for (int i = 0; i < a.length; i++)
            p(a[i] + " ");
        pn("");
    }

    static long count(long n) {
        long count = 0;
        while (n != 0) {
            count += n % 10;
            n /= 10;
        }
        return count;
    }

    static void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    static int LcsOfPrefix(String a, String b) {
        int i = 0;
        int j = 0;
        int count = 0;
        while (i < a.length() && j < b.length()) {
            if (a.charAt(i) == b.charAt(j)) {
                j++;
                count++;
            }
            i++;
        }
        return a.length() + b.length() - 2 * count;
    }

    static void reverse(int[] a, int n) {
        for (int i = 0; i < n / 2; i++) {
            int temp = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = temp;
        }
    }

    static char get_char(int a) {
        return (char) (a + 'a');
    }

    static int find1(int[] a, int val) {
        int ans = -1;
        int l = 0;
        int r = a.length - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (a[mid] <= val) {
                l = mid + 1;
                ans = mid;
            } else
                r = mid - 1;
        }
        return ans;
    }

    static int find2(int[] a, int val) {
        int l = 0;
        int r = a.length - 1;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (a[mid] <= val) {
                ans = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return ans;
    }

    // static void dfs(List<List<Integer>> arr, int node, int parent, long[] val) {
    // p[node] = parent;
    // in_time[node] = count;
    // flat_tree[count] = val[node];
    // subtree_gcd[node] = val[node];
    // count++;
    // for (int adj : arr.get(node)) {
    // if (adj == parent)
    // continue;
    // dfs(arr, adj, node, val);
    // subtree_gcd[node] = gcd(subtree_gcd[adj], subtree_gcd[node]);
    // }
    // out_time[node] = count;
    // flat_tree[count] = val[node];
    // count++;
    // }
}