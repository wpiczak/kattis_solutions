#include <algorithm>
#include <cstddef>
#include <iostream>
#include <stdexcept>

template<typename T>
class ordered_set {
    struct node {
        T value;
        node* left_child{nullptr};
        node* right_child{nullptr};
        node* parent{nullptr};
        std::size_t left_subtree_size{0};
        std::size_t right_subtree_size{0};
        int height{0};

        explicit node(T&& value);
        explicit node(const T& value);

        [[nodiscard]] int balance_factor() const;

        void connect_left_child(node* child);
        void connect_right_child(node* child);
        void update();

        node* next(const node* previous) const;
        node* previous(const node* next) const;

        node* next_pre_order() const;
        node* next_in_order() const;
        node* next_post_order() const;
        node* previous_pre_order() const;
        node* previous_in_order() const;
        node* previous_post_order() const;

        static int get_height(const node* current);
        static std::size_t get_size(const node* current);
    };

public:
    class iterator {
        explicit iterator(const node* current, const ordered_set& set);

    public:
        using iterator_category = std::random_access_iterator_tag;

        iterator() = default;

        bool operator==(const iterator& other) const;
        bool operator!=(const iterator& other) const;

        iterator& operator++();
        iterator operator++(int);
        iterator& operator--();
        iterator operator--(int);

        const T& operator*() const;
        const T* operator->() const;

    private:
        const node* current{nullptr};
        const ordered_set& set;

        friend ordered_set;
    };

    using reverse_iterator = std::reverse_iterator<iterator>;

    ordered_set() = default;
    ordered_set(ordered_set&& other) noexcept;
    ordered_set(const ordered_set& other);
    ~ordered_set();

    ordered_set& operator=(ordered_set&& other) noexcept;
    ordered_set& operator=(ordered_set other);

    bool operator==(const ordered_set& other) const;
    bool operator!=(const ordered_set& other) const;

    [[nodiscard]] iterator begin() const;
    [[nodiscard]] iterator end() const;
    [[nodiscard]] reverse_iterator rbegin() const;
    [[nodiscard]] reverse_iterator rend() const;

    [[nodiscard]] std::size_t size() const;
    [[nodiscard]] iterator find(const T& value) const;

    [[nodiscard]] const T& find_by_order(std::size_t n) const;
    [[nodiscard]] std::size_t order_of_key(const T& value) const;

    std::pair<iterator, bool> insert(T&& value);
    std::pair<iterator, bool> insert(const T& value);
    void erase(iterator position);

    friend void swap(ordered_set& first, ordered_set& second) noexcept {
        std::swap(first.root_, second.root_);
        std::swap(first.first_, second.first_);
        std::swap(first.last_, second.last_);
    }

    template<typename>
    friend class tree_tester;

private:
    node* root_{nullptr};
    node* first_{nullptr};
    node* last_{nullptr};

    void bubble_update(node* start);

    node* insert(node* new_node);
    void erase(node* current);

    void balance(node* current);
    void rotate_left(node* current);
    void rotate_right(node* current);

    static node* find(node* current, const T& value);
    static node* find_successor(node* current);
};

template<typename T>
ordered_set<T>::node::node(T&& value) : value{std::move(value)} {}

template<typename T>
ordered_set<T>::node::node(const T& value) : value{value} {}

template<typename T>
int ordered_set<T>::node::balance_factor() const {
    return get_height(right_child) - get_height(left_child);
}

template<typename T>
void ordered_set<T>::node::connect_left_child(node* child) {
    if (child != nullptr) child->parent = this;
    left_child = child;
    update();
}

template<typename T>
void ordered_set<T>::node::connect_right_child(node* child) {
    if (child != nullptr) child->parent = this;
    right_child = child;
    update();
}

template<typename T>
void ordered_set<T>::node::update() {
    left_subtree_size = get_size(left_child);
    right_subtree_size = get_size(right_child);
    height = std::max(get_height(left_child), get_height(right_child)) + 1;
}

template<typename T>
ordered_set<T>::node* ordered_set<T>::node::next(const node* const previous) const {
    if (previous == parent) {
        if (left_child != nullptr) return left_child;
        if (right_child != nullptr) return right_child;
        return parent;
    }

    if (previous == left_child) {
        if (right_child != nullptr) return right_child;
        return parent;
    }

    return parent;
}

template<typename T>
ordered_set<T>::node* ordered_set<T>::node::previous(const node* const next) const {
    if (next == parent) {
        if (right_child != nullptr) return right_child;
        if (left_child != nullptr) return left_child;
        return parent;
    }

    if (next == right_child) {
        if (left_child != nullptr) return left_child;
        return parent;
    }

    return parent;
}

template<typename T>
ordered_set<T>::node* ordered_set<T>::node::next_pre_order() const {
    auto previous = parent;
    auto current = const_cast<node*>(this);

    while (true) {
        auto next = current->next(previous);
        previous = current;
        current = next;

        if (current == nullptr) return nullptr;
        if (previous == current->parent) return current;
    }
}

template<typename T>
ordered_set<T>::node* ordered_set<T>::node::next_in_order() const {
    auto previous = (left_child != nullptr) ? left_child : parent;
    auto current = const_cast<node*>(this);

    while (true) {
        auto next = current->next(previous);
        previous = current;
        current = next;

        if (current == nullptr) return nullptr;
        if (current->left_child != nullptr) {
            if (previous == current->left_child) return current;
        } else if (previous == current->parent) return current;
    }
}

template<typename T>
ordered_set<T>::node* ordered_set<T>::node::next_post_order() const {
    auto previous = (right_child != nullptr) ? right_child : ((left_child != nullptr) ? left_child : parent);
    auto current = const_cast<node*>(this);

    while (true) {
        auto next = current->next(previous);
        previous = current;
        current = next;

        if (current == nullptr) return nullptr;
        if (current->right_child != nullptr) {
            if (previous == current->right_child) return current;
        } else if (current->left_child != nullptr) {
            if (previous == current->left_child) return current;
        } else if (previous == current->parent) return current;
    }
}

template<typename T>
ordered_set<T>::node* ordered_set<T>::node::previous_pre_order() const {
    auto next = (left_child != nullptr) ? left_child : ((right_child != nullptr) ? right_child : parent);
    auto current = const_cast<node*>(this);

    while (true) {
        auto previous = current->previous(next);
        next = current;
        current = previous;

        if (current == nullptr) return nullptr;
        if (current->left_child != nullptr) {
            if (next == current->left_child) return current;
        } else if (current->right_child != nullptr) {
            if (next == current->right_child) return current;
        } else if (next == current->parent) return current;
    }
}

template<typename T>
ordered_set<T>::node* ordered_set<T>::node::previous_in_order() const {
    auto next = (right_child != nullptr) ? right_child : parent;
    auto current = const_cast<node*>(this);

    while (true) {
        auto previous = current->previous(next);
        next = current;
        current = previous;

        if (current == nullptr) return nullptr;
        if (current->right_child != nullptr) {
            if (next == current->right_child) return current;
        } else if (next == current->parent) return current;
    }
}

template<typename T>
ordered_set<T>::node* ordered_set<T>::node::previous_post_order() const {
    auto next = parent;
    auto current = const_cast<node*>(this);

    while (true) {
        auto previous = current->previous(next);
        next = current;
        current = previous;

        if (current == nullptr) return nullptr;
        if (next == current->parent) return current;
    }
}

template<typename T>
int ordered_set<T>::node::get_height(const node* const current) {
    if (current == nullptr) return -1;
    return current->height;
}

template<typename T>
std::size_t ordered_set<T>::node::get_size(const node* const current) {
    if (current == nullptr) return 0;
    return current->left_subtree_size + current->right_subtree_size + 1;
}

template<typename T>
ordered_set<T>::iterator::iterator(const node* current, const ordered_set& set) : current{current}, set{set} {}

template<typename T>
bool ordered_set<T>::iterator::operator==(const iterator& other) const { return current == other.current; }

template<typename T>
bool ordered_set<T>::iterator::operator!=(const iterator& other) const { return current != other.current; }

template<typename T>
ordered_set<T>::iterator& ordered_set<T>::iterator::operator++() {
    if (current == nullptr) current = set.first_;
    else current = current->next_in_order();
    return *this;
}

template<typename T>
ordered_set<T>::iterator ordered_set<T>::iterator::operator++(int) {
    auto temp = *this;
    ++temp;
    return temp;
}

template<typename T>
ordered_set<T>::iterator& ordered_set<T>::iterator::operator--() {
    if (current == nullptr) current = set.last_;
    else current = current->previous_in_order();
    return *this;
}

template<typename T>
ordered_set<T>::iterator ordered_set<T>::iterator::operator--(int) {
    auto temp = *this;
    --temp;
    return temp;
}

template<typename T>
const T& ordered_set<T>::iterator::operator*() const { return current->value; }

template<typename T>
const T* ordered_set<T>::iterator::operator->() const { return *current->value; }

template<typename T>
ordered_set<T>::ordered_set(ordered_set&& other) noexcept
    : root_{other.root_}, first_{other.first_}, last_{other.last_} {
    other.root_ = nullptr;
    other.first_ = nullptr;
    other.last_ = nullptr;
}

template<typename T>
ordered_set<T>::ordered_set(const ordered_set& other) {
    if (other.root_ == nullptr) return;

    root_ = new node{other.root_->value};

    auto source = other.root_;
    auto destination = root_;
    while (source != nullptr) {
        if (source->left_child != nullptr) destination->connect_left_child(new node{source->left_child->value});
        if (source->right_child != nullptr) destination->connect_right_child(new node{source->right_child->value});
        if (source == other.first_) first_ = destination;
        if (source == other.last_) last_ = destination;

        source = source->next_pre_order();
        destination = destination->next_pre_order();
    }
}

template<typename T>
ordered_set<T>::~ordered_set() {
    if (root_ == nullptr) return;

    auto current = root_;
    while (true) {
        if (current->left_child != nullptr) current = current->left_child;
        else if (current->right_child != nullptr) current = current->right_child;
        else break;
    }

    while (current != nullptr) {
        auto next = current->next_post_order();
        delete current;
        current = next;
    }
}

template<typename T>
ordered_set<T>& ordered_set<T>::operator=(ordered_set&& other) noexcept {
    std::swap(*this, other);
    return *this;
}

template<typename T>
ordered_set<T>& ordered_set<T>::operator=(ordered_set other) {
    swap(*this, other);
    return *this;
}

template<typename T>
bool ordered_set<T>::operator==(const ordered_set& other) const {
    auto it = begin();
    auto other_it = other.begin();

    while (it != end() && other_it != other.end())
        if (*it != *other_it) return false;

    return it == end() && other == other.end();
}

template<typename T>
bool ordered_set<T>::operator!=(const ordered_set& other) const { return !(*this == other); }

template<typename T>
ordered_set<T>::iterator ordered_set<T>::begin() const { return iterator{first_, *this}; }

template<typename T>
ordered_set<T>::iterator ordered_set<T>::end() const { return iterator{nullptr, *this}; }

template<typename T>
ordered_set<T>::reverse_iterator ordered_set<T>::rbegin() const { return std::reverse_iterator<iterator>(end()); }

template<typename T>
ordered_set<T>::reverse_iterator ordered_set<T>::rend() const { return std::reverse_iterator<iterator>(begin()); }

template<typename T>
std::size_t ordered_set<T>::size() const { return node::get_size(root_); }

template<typename T>
ordered_set<T>::iterator ordered_set<T>::find(const T& value) const { return iterator{find(root_, value), *this}; }

template<typename T>
const T& ordered_set<T>::find_by_order(std::size_t n) const {
    if (n >= size()) throw std::logic_error("index out of bounds");

    auto current = root_;
    while (true) {
        if (n < current->left_subtree_size) current = current->left_child;
        else if (n > current->left_subtree_size) {
            n -= current->left_subtree_size + 1;
            current = current->right_child;
        } else return current->value;
    }
}

template<typename T>
std::size_t ordered_set<T>::order_of_key(const T& value) const {
    std::size_t rank = 0;
    auto current = root_;

    while (current != nullptr) {
        rank += current->left_subtree_size;

        if (value < current->value) {
            rank -= current->left_subtree_size;
            current = current->left_child;
        } else if (value > current->value) {
            rank += 1;
            current = current->right_child;
        } else break;
    }

    return rank;
}

template<typename T>
std::pair<typename ordered_set<T>::iterator, bool> ordered_set<T>::insert(T&& value) {
    auto new_node = new node{std::move(value)};
    auto current = insert(new_node);
    return {iterator{current, *this}, current == new_node};
}

template<typename T>
std::pair<typename ordered_set<T>::iterator, bool> ordered_set<T>::insert(const T& value) {
    auto new_node = new node{value};
    auto current = insert(new_node);
    return {iterator{current, *this}, current == new_node};
}

template<typename T>
void ordered_set<T>::erase(iterator position) {
    if (position.current != nullptr) erase(const_cast<node*>(position.current));
}

template<typename T>
void ordered_set<T>::bubble_update(node* start) {
    while (start != nullptr) {
        balance(start);
        start->update();
        start = start->parent;
    }
}

template<typename T>
ordered_set<T>::node* ordered_set<T>::insert(node* new_node) {
    if (root_ == nullptr) {
        root_ = new_node;
        first_ = new_node;
        last_ = new_node;

        return new_node;
    }

    auto parent = root_;
    while (true) {
        if (new_node->value < parent->value) {
            if (parent->left_child == nullptr) {
                parent->connect_left_child(new_node);
                if (parent == first_) first_ = new_node;
                break;
            }

            parent = parent->left_child;
        } else if (new_node->value > parent->value) {
            if (parent->right_child == nullptr) {
                parent->connect_right_child(new_node);
                if (parent == last_) last_ = new_node;
                break;
            }

            parent = parent->right_child;
        } else return parent;
    }

    bubble_update(new_node);

    return new_node;
}

template<typename T>
void ordered_set<T>::erase(node* current) {
    if (current->left_child != nullptr && current->right_child != nullptr) {
        auto successor = find_successor(current);

        using std::swap;
        swap(current->value, successor->value);

        current = successor;
    }

    node* successor = nullptr;
    if (current->left_child != nullptr) {
        successor = current->left_child;
        if (current == last_) last_ = successor;
    } else if (current->right_child != nullptr) {
        successor = current->right_child;
        if (current == first_) first_ = successor;
    } else {
        if (current == first_) first_ = current->parent;
        if (current == last_) last_ = current->parent;
    }

    if (current == root_) {
        if (successor != nullptr) successor->parent = nullptr;
        root_ = successor;
    } else {
        auto parent = current->parent;

        if (parent->left_child == current) parent->connect_left_child(successor);
        else parent->connect_right_child(successor);

        bubble_update(parent);
    }

    delete current;
}

template<typename T>
void ordered_set<T>::balance(node* current) {
    if (current->balance_factor() == 2) {
        if (current->right_child->balance_factor() == -1)
            rotate_right(current->right_child);
        rotate_left(current);
    }

    if (current->balance_factor() == -2) {
        if (current->left_child->balance_factor() == 1)
            rotate_left(current->left_child);
        rotate_right(current);
    }
}

template<typename T>
void ordered_set<T>::rotate_left(node* current) {
    auto successor = current->right_child;
    auto parent = current->parent;

    current->connect_right_child(successor->left_child);
    successor->connect_left_child(current);

    if (parent == nullptr) {
        successor->parent = nullptr;
        root_ = successor;
        return;
    }

    if (parent->left_child == current) parent->connect_left_child(successor);
    else parent->connect_right_child(successor);
}

template<typename T>
void ordered_set<T>::rotate_right(node* current) {
    auto successor = current->left_child;
    auto parent = current->parent;

    current->connect_left_child(successor->right_child);
    successor->connect_right_child(current);

    if (parent == nullptr) {
        successor->parent = nullptr;
        root_ = successor;
        return;
    }

    if (parent->left_child == current) parent->connect_left_child(successor);
    else parent->connect_right_child(successor);
}

template<typename T>
ordered_set<T>::node* ordered_set<T>::find(node* current, const T& value) {
    while (current != nullptr) {
        if (value < current->value) current = current->left_child;
        else if (value > current->value) current = current->right_child;
        else return current;
    }

    return nullptr;
}

template<typename T>
ordered_set<T>::node* ordered_set<T>::find_successor(node* current) {
    if (current->balance_factor() < 0) {
        current = current->left_child;
        while (current->right_child != nullptr)
            current = current->right_child;
    } else {
        current = current->right_child;
        while (current->left_child != nullptr)
            current = current->left_child;
    }

    return current;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    ordered_set<std::string> boy_names;
    ordered_set<std::string> girl_names;

    int command;
    while (std::cin >> command) {
        if (command == 0) break;
        if (command == 1) {
            std::string name;
            int gender;
            std::cin >> name >> gender;

            if (gender == 1) boy_names.insert(name);
            else if (gender == 2) girl_names.insert(name);
        } else if (command == 2) {
            std::string name;
            std::cin >> name;

            boy_names.erase(boy_names.find(name));
            girl_names.erase(girl_names.find(name));
        } else if (command == 3) {
            std::string start;
            std::string end;
            int gender;
            std::cin >> start >> end >> gender;

            std::size_t result = 0;
            if (gender == 0 || gender == 1)
                result += boy_names.order_of_key(end) - boy_names.order_of_key(start);
            if (gender == 0 || gender == 2)
                result += girl_names.order_of_key(end) - girl_names.order_of_key(start);
            std::cout << result << '\n';
        }
    }

    return 0;
}
