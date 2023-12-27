#include <iostream>
#include <map>
#include <array>

// Allocator
template <typename T, size_t N>
class MyAllocator {
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;

    template <typename U>
    struct rebind {
        using other = MyAllocator<U, N>;
    };

    MyAllocator() : memory_(), position_(memory_.begin()) {}

    template <typename U>
    MyAllocator(const MyAllocator<U, N>&) noexcept {}

    T* allocate(std::size_t n) {
        if (position_ + n <= memory_.end()) {
            T* result = &(*position_);
            position_ += n;
            return result;
        } else {
            throw std::bad_alloc();
        }
    }

    void deallocate(T*, std::size_t) noexcept {
        
    }

private:
    std::array<T, N> memory_;
    typename std::array<T, N>::iterator position_;
};

// List
template <typename T, typename Allocator = std::allocator<T>>
class MyList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

public:
    // Iterator
    class Iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        Iterator(Node* node) : current_(node) {}

        Iterator& operator++() {
            current_ = current_->next;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const Iterator& other) const {
            return current_ == other.current_;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }

        T& operator*() const {
            return current_->data;
        }

        T* operator->() const {
            return &(current_->data);
        }

    private:
        Node* current_;
    };

    using allocator_type = Allocator;
    using value_type = typename Allocator::value_type;

    MyList() : head_(nullptr), tail_(nullptr), size_(0) {}

    void push_back(const T& value) {
        Node* newNode = allocator_.allocate(1);
        newNode->data = value;
        newNode->prev = tail_;
        newNode->next = nullptr;

        if (tail_ != nullptr) {
            tail_->next = newNode;
        }

        tail_ = newNode;

        if (head_ == nullptr) {
            head_ = newNode;
        }

        ++size_;
    }

    Iterator begin() {
        return Iterator(head_);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

private:
    Node* head_;
    Node* tail_;
    size_t size_;
    Allocator allocator_;
};

int main() {
    std::map<int, int, std::less<int>, MyAllocator<std::pair<const int, int>, 10>> myMapAllocator;

    for (int i = 0; i < 10; ++i) {
        myMapAllocator[i] = (i == 0) ? 1 : i * myMapAllocator[i - 1];
    }

    for (const auto& pair : myMapAllocator) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    MyList<int, MyAllocator<int, 10>> myListAllocator;
    for (int i = 0; i < 10; ++i) {
        myListAllocator.push_back(i);
    }

    for (const auto& value : myListAllocator) {
        std::cout << value << " ";
    }

    return 0;
}
