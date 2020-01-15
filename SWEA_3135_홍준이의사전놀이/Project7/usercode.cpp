class word_tree {
private:
    int counts, lv;
    word_tree* childs[26];
public:
    word_tree(int lv, int count = 1) {
        *this->childs = { nullptr, };
        this->counts = count;
        this->lv = lv;
    }

    void insert(char* target, int len) {
        ++this->counts;
        if (this->lv == len) return;
        if (this->childs[target[(this->lv)] - 'a'] == nullptr) create(target, len);
        else if (this->lv < len) this->childs[target[this->lv] - 'a']->insert(target, len);
    }

    void create(char* target, int len) {
        if (this->lv == len) return;
        this->childs[target[this->lv] - 'a'] = new word_tree(this->lv + 1);
        if (this->lv < len) this->childs[target[this->lv] - 'a']->create(target, len);
    }

    int count(char* target, int len) {
        if (this->lv == len) return this->counts;
        else if (this->childs[target[this->lv] - 'a'] == nullptr) return 0;
        else return this->childs[target[this->lv] - 'a']->count(target, len);
    }
};

word_tree* Root;

void init(void) {
    Root = new word_tree(0, 0);
}

void insert(int buffer_size, char* buf) {
    Root->insert(buf, buffer_size);
}

int query(int buffer_size, char* buf) {
    return Root->count(buf, buffer_size);
}