class MyHashSet {
public:
    vector<list<int>> arr;
    int size;

    MyHashSet() {
        size = 1000;
        arr.resize(size);
    }

    void add(int key) {
        int index = key % size;

        for (int x : arr[index]) {
            if (x == key)
                return;
        }

        arr[index].push_back(key);
    }

    void remove(int key) {
        int index = key % size;

        arr[index].remove(key);
    }

    bool contains(int key) {
        int index = key % size;

        for (int x : arr[index]) {
            if (x == key)
                return true;
        }

        return false;
    }
};