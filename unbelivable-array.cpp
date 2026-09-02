#include <iostream>
#include <vector>
#include <map>
using namespace std;

template <typename K, typename V>
static bool contains(const std::map<K, V> &m, const K &key) {
    return m.find(key) != m.end();
}

// Find with path compression
static int find(vector<int> &ldr, const int x) {
    if (ldr[x] == x)
        return x;
    return ldr[x] = find(ldr, ldr[x]);
}

// Union
static void join(vector<int> &ldr, int lt, int rt) {
    lt = find(ldr, lt);
    rt = find(ldr, rt);
    if (lt != rt)
        ldr[lt] = rt;
}

static void solve() {
    int N, Q;
    cin >> N >> Q;

    vector<int> a(N + 1), ldr(N + 1);

    map<int, int> vlm;   // value -> leader index
    map<int, int> lvm;   // leader index -> value

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        ldr[i] = i; // MINIMAL FIX 1: Every position must initialize its own DSU path

        // MINIMAL FIX 2: Changed to !contains (Logic was upside down)
        if (!contains(vlm, a[i])) {
            vlm[a[i]] = i;
            lvm[i] = a[i];
        }
        else {
            ldr[i] = vlm[a[i]];
        }
    }

    while (Q--) {
        int qt;
        cin >> qt;

        if (qt == 1) {
            int x, y;
            cin >> x >> y;

            if (x == y)
                continue;

            if (!contains(vlm, x))
                continue;

            if (!contains(vlm, y)) {
                int x_leader = find(ldr, vlm[x]);
                lvm[x_leader] = y;
                vlm[y] = vlm[x];
                vlm.erase(x);
            } else {
                int x_track = vlm[x];
                int y_track = vlm[y];

                join(ldr, x_track, y_track);

                int newLeader = find(ldr, y_track);
                lvm[newLeader] = y;

                // MINIMAL FIX 3: Point y's reference to the new unified root
                vlm[y] = newLeader;
                vlm.erase(x);
            }
        } else {
            int idx;
            cin >> idx;

            int uldr = find(ldr, idx);
            cout << lvm[uldr] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc, ca = 1;
   cin>>tc;
        while (tc--) {
            cout << "Case " << ca++ << ":\n";
            solve();
        }
    return 0;
}
