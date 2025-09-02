#include <iostream>
#include <unordered_map>
#include <vector>

class priority_queue {
    struct entry {
        int priority;
        std::size_t chrono_index;

        bool operator<(const entry& other) const {
            if (priority < other.priority) return true;
            if (priority > other.priority) return false;

            return chrono_index > other.chrono_index;
        }
    };

public:
    void insert(const std::string& key, const int priority, const std::size_t chrono_index) {
        const auto it = key_to_index_.find(key);
        if (it != key_to_index_.end()) throw std::logic_error("key already present");

        const std::size_t index = data_.size();
        key_to_index_[key] = index;
        index_to_key_.push_back(key);
        data_.push_back({priority, chrono_index});
        bubble_up(index);
    }

    void increase_key(const std::string& key, const int delta) {
        if (delta < 0) throw std::logic_error("delta is negative");
        if (delta == 0) return;

        const auto it = key_to_index_.find(key);
        if (it == key_to_index_.end()) throw std::logic_error("key not found");

        const std::size_t index = it->second;
        data_[index].priority += delta;
        bubble_up(index);
    }

    void remove(const std::string& key) {
        const auto it = key_to_index_.find(key);
        if (it == key_to_index_.end()) throw std::logic_error("key not found");

        const std::size_t index = it->second;
        swap(index, data_.size() - 1);

        key_to_index_.erase(it);
        index_to_key_.pop_back();
        data_.pop_back();
        bubble_down(index);
        bubble_up(index);
    }

    bool is_empty() const { return data_.empty(); }

    std::string query() const { return index_to_key_[0]; }

private:
    std::unordered_map<std::string, std::size_t> key_to_index_;
    std::vector<std::string> index_to_key_;
    std::vector<entry> data_;

    static std::size_t parent(const std::size_t index) { return (index - 1) / 2; }
    static std::size_t left_child(const std::size_t index) { return 2 * index + 1; }
    static std::size_t right_child(const std::size_t index) { return 2 * index + 2; }

    void bubble_up(std::size_t index) {
        while (index > 0 && data_[parent(index)] < data_[index]) {
            swap(index, parent(index));
            index = parent(index);
        }
    }

    void bubble_down(std::size_t index) {
        while (index < data_.size()) {
            std::size_t next_index = index;

            if (left_child(index) < data_.size() && data_[next_index] < data_[left_child(index)])
                next_index = left_child(index);

            if (right_child(index) < data_.size() && data_[next_index] < data_[right_child(index)])
                next_index = right_child(index);

            if (next_index == index) break;

            swap(index, next_index);
            index = next_index;
        }
    }

    void swap(const std::size_t first, const std::size_t second) {
        std::swap(key_to_index_[index_to_key_[first]], key_to_index_[index_to_key_[second]]);
        std::swap(index_to_key_[first], index_to_key_[second]);
        std::swap(data_[first], data_[second]);
    }
};

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int command_count;
    std::cin >> command_count;

    priority_queue clinic_queue;
    for (int i = 0; i < command_count; ++i) {
        int command_type;
        std::cin >> command_type;

        if (command_type == 0) {
            std::string name;
            int infection_level;
            std::cin >> name >> infection_level;

            clinic_queue.insert(name, infection_level, i);
        } else if (command_type == 1) {
            std::string name;
            int infection_level_delta;
            std::cin >> name >> infection_level_delta;

            clinic_queue.increase_key(name, infection_level_delta);
        } else if (command_type == 2) {
            std::string name;
            std::cin >> name;

            clinic_queue.remove(name);
        } else if (command_type == 3) {
            if (clinic_queue.is_empty()) std::cout << "The clinic is empty\n";
            else std::cout << clinic_queue.query() << '\n';
        }
    }

    return 0;
}
