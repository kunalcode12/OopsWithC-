#include <cstdio>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> vi;

class UnionFind {
private:
    vi rank, setSize, p;
    int numSets;

public:
    UnionFind(int N) {
        rank.assign(N, 0);
        setSize.assign(N, 1);
        p.assign(N, 0);
        numSets = N;
        for (int i = 0; i < N; i++) p[i] = i;
    }

    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            --numSets;
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) {
                p[y] = x;
                setSize[x] += setSize[y];
            } else {
                p[x] = y;
                setSize[y] += setSize[x];
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }

    int numDisjointSets() {
        return numSets;
    }

    int sizeOfSet(int i) {
        return setSize[i];
    }
};

class SegmentTree {
private:
    vi st, A;
    int n;

    int left(int p) {
        return (p << 1);
    }

    int right(int p) {
        return (p << 1) + 1;
    }

    void build(int p, int L, int R) {
        if (L == R) {
            st[p] = L;
        } else {
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] < A[p2]) ? p1 : p2;
        }
    }

    int rmq(int p, int L, int R, int i, int j) {
        if (i > R || j < L) return -1;
        if (L >= i && R <= j) return st[p];

        int p1 = rmq(left(p), L, (L + R) / 2, i, j);
        int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

        if (p1 == -1) return p2;
        if (p2 == -1) return p1;

        return (A[p1] < A[p2]) ? p1 : p2;
    }

    int update_point(int p, int L, int R, int idx, int new_value) {
        int i = idx, j = idx;
        if (i > R || j < L) return st[p];
        if (L == i && R == j) {
            A[i] = new_value;
            return st[p] = L;
        }

        int p1 = update_point(left(p), L, (L + R) / 2, idx, new_value);
        int p2 = update_point(right(p), (L + R) / 2 + 1, R, idx, new_value);

        return st[p] = (A[p1] < A[p2]) ? p1 : p2;
    }

public:
    SegmentTree(const vi &_A) {
        A = _A;
        n = (int)A.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    int rmq(int i, int j) {
        return rmq(1, 0, n - 1, i, j);
    }

    int update_point(int idx, int new_value) {
        return update_point(1, 0, n - 1, idx, new_value);
    }
};

int main(int argc, char *argv[]) {
    printf("Assume that there are 5 disjoint sets initially\n");

    UnionFind UF(5); // create 5 disjoint sets
    printf("%d\n", UF.numDisjointSets()); // 5
    UF.unionSet(0, 1);
    printf("%d\n", UF.numDisjointSets()); // 4
    UF.unionSet(2, 3);
    printf("%d\n", UF.numDisjointSets()); // 3
    UF.unionSet(4, 3);
    printf("%d\n", UF.numDisjointSets()); // 2
    printf("isSameSet(0, 3) = %d\n", UF.isSameSet(0, 3)); // false
    printf("isSameSet(4, 3) = %d\n", UF.isSameSet(4, 3)); // true

    for (int i = 0; i < 5; i++) {
        printf("findSet(%d) = %d, sizeOfSet(%d) = %d\n", i, UF.findSet(i), i, UF.sizeOfSet(i));
    }

    UF.unionSet(0, 3);
    printf("%d\n", UF.numDisjointSets()); // 1

    for (int i = 0; i < 5; i++) {
        printf("findSet(%d) = %d, sizeOfSet(%d) = %d\n", i, UF.findSet(i), i, UF.sizeOfSet(i));
    }

    int arr[] = {18, 17, 13, 19, 15, 11, 20};
    vi A(arr, arr + 7);
    SegmentTree st(A);

    printf("              idx    0, 1, 2, 3, 4,  5, 6\n");
    printf("              A is {18,17,13,19,15, 11,20}\n");
    printf("RMQ(1, 3) = %d\n", st.rmq(1, 3)); // index 2
    printf("RMQ(4, 6) = %d\n", st.rmq(4, 6)); // index 5
    printf("RMQ(3, 4) = %d\n", st.rmq(3, 4)); // index 4
    printf("RMQ(0, 0) = %d\n", st.rmq(0, 0)); // index 0
    printf("RMQ(0, 1) = %d\n", st.rmq(0, 1)); // index 1
    printf("RMQ(0, 6) = %d\n", st.rmq(0, 6)); // index 5

    printf("              idx    0, 1, 2, 3, 4,  5, 6\n");
    printf("Now, modify A into {18,17,13,19,15,100,20}\n");
    st.update_point(5, 100);

    printf("These values do not change\n");
    printf("RMQ(1, 3) = %d\n", st.rmq(1, 3)); // index 2
    printf("RMQ(3, 4) = %d\n", st.rmq(3, 4)); // index 4
    printf("RMQ(0, 0) = %d\n", st.rmq(0, 0)); // index 0
    printf("RMQ(0, 1) = %d\n", st.rmq(0, 1)); // index 1

    printf("These values change\n");
    printf("RMQ(0, 6) = %d\n", st.rmq(0, 6)); // index 2
    printf("RMQ(4, 6) = %d\n", st.rmq(4, 6)); // index 4
    printf("RMQ(4, 5) = %d\n", st.rmq(4, 5)); // index 4

    return 0;
}
