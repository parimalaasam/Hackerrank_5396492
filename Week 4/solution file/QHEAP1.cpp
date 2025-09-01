#include <iostream>
#include <set>

using namespace std;

class Heap {
private:
    multiset<int> heap;

public:
    void insert(int val) {
        heap.insert(val);
    }

    void remove(int val) {
        auto it = heap.find(val);
        if (it != heap.end()) {
            heap.erase(it);
        }
    }

    void minimum() {
        if (!heap.empty()) {
            cout << *heap.begin() << endl;
        }
    }
};

int main() {
    int q;
    cin >> q;

    Heap heap;
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int val;
            cin >> val;
            heap.insert(val);
        } else if (type == 2) {
            int val;
            cin >> val;
            heap.remove(val);
        } else if (type == 3) {
            heap.minimum();
        }
    }

    return 0;
}
