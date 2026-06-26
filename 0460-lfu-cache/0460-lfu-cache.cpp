class Node {
public:
    int key, val, freq;
    Node *prev, *next;

    Node(int k, int v) {
        key = k;
        val = v;
        freq = 1;
        prev = next = NULL;
    }
};

class List {
public:
    int size;
    Node *head, *tail;

    List() {
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void addFront(Node *node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;

        size++;
    }

    void remove(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }
};

class LFUCache {
public:

    int capacity;
    int curSize;
    int minFreq;

    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;

    LFUCache(int capacity) {
        this->capacity = capacity;
        curSize = 0;
        minFreq = 0;
    }

    void updateFreq(Node *node) {

        keyNode.erase(node->key);

        freqList[node->freq]->remove(node);

        if (node->freq == minFreq &&
            freqList[node->freq]->size == 0)
            minFreq++;

        node->freq++;

        if (freqList.find(node->freq) == freqList.end())
            freqList[node->freq] = new List();

        freqList[node->freq]->addFront(node);

        keyNode[node->key] = node;
    }

    int get(int key) {

        if (keyNode.find(key) == keyNode.end())
            return -1;

        Node *node = keyNode[key];

        updateFreq(node);

        return node->val;
    }

    void put(int key, int value) {

        if (capacity == 0)
            return;

        if (keyNode.find(key) != keyNode.end()) {

            Node *node = keyNode[key];
            node->val = value;

            updateFreq(node);
            return;
        }

        if (curSize == capacity) {

            List *list = freqList[minFreq];

            Node *node = list->tail->prev;

            list->remove(node);

            keyNode.erase(node->key);

            curSize--;
        }

        curSize++;

        minFreq = 1;

        if (freqList.find(1) == freqList.end())
            freqList[1] = new List();

        Node *node = new Node(key, value);

        freqList[1]->addFront(node);

        keyNode[key] = node;
    }
};