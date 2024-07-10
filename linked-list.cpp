#include <iostream>

// Node structure for the linked list
template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;
    
    Node(const T& val) : data(val), next(nullptr), prev(nullptr) {}
};

// Iterator for the list
template <typename T>
struct ListIterator {
    Node<T>* current;
    
    ListIterator(Node<T>* node) : current(node) {}
    
    T& operator*() const {
        return current->data;
    }
    
    ListIterator<T>& operator++() {
        current = current->next;
        return *this;
    }
    
    bool operator!=(const ListIterator<T>& other) const {
        return current != other.current;
    }
};

// Reverse iterator for the list
template <typename T>
struct ListReverseIterator {
    Node<T>* current;
    
    ListReverseIterator(Node<T>* node) : current(node) {}
    
    T& operator*() const {
        return current->data;
    }
    
    ListReverseIterator<T>& operator++() {
        current = current->prev;
        return *this;
    }
    
    bool operator!=(const ListReverseIterator<T>& other) const {
        return current != other.current;
    }
};

// List container implementation
template <typename T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t list_size;

public:
    // Constructor
    List() : head(nullptr), tail(nullptr), list_size(0) {}

    // Destructor
    ~List() {
        clear();
    }

    // Iterator methods
    ListIterator<T> begin() {
        return ListIterator<T>(head);
    }

    ListIterator<T> end() {
        return ListIterator<T>(nullptr);
    }

    ListReverseIterator<T> rbegin() {
        return ListReverseIterator<T>(tail);
    }

    ListReverseIterator<T> rend() {
        return ListReverseIterator<T>(nullptr);
    }

    // Const iterator methods
    ListIterator<const T> cbegin() const {
        return ListIterator<const T>(head);
    }

    ListIterator<const T> cend() const {
        return ListIterator<const T>(nullptr);
    }

    ListReverseIterator<const T> crbegin() const {
        return ListReverseIterator<const T>(tail);
    }

    ListReverseIterator<const T> crend() const {
        return ListReverseIterator<const T>(nullptr);
    }

    // Capacity methods
    bool empty() const {
        return list_size == 0;
    }

    size_t size() const {
        return list_size;
    }

    size_t max_size() const {
        // A practical implementation would determine system limits
        return std::numeric_limits<size_t>::max();
    }

    // Element access methods
    T& front() {
        return head->data;
    }

    const T& front() const {
        return head->data;
    }

    T& back() {
        return tail->data;
    }

    const T& back() const {
        return tail->data;
    }

    // Modifier methods
    void assign(size_t count, const T& value) {
        clear();
        for (size_t i = 0; i < count; ++i) {
            push_back(value);
        }
    }

    void emplace_front(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (empty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        ++list_size;
    }

    void push_front(const T& value) {
        emplace_front(value);
    }

    void pop_front() {
        if (!empty()) {
            Node<T>* temp = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete temp;
            --list_size;
        }
    }

    void emplace_back(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (empty()) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        ++list_size;
    }

    void push_back(const T& value) {
        emplace_back(value);
    }

    void pop_back() {
        if (!empty()) {
            Node<T>* temp = tail;
            tail = tail->prev;
            if (tail) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }
            delete temp;
            --list_size;
        }
    }

    void emplace(ListIterator<T> pos, const T& value) {
        Node<T>* current = pos.current;
        if (current) {
            Node<T>* newNode = new Node<T>(value);
            newNode->next = current;
            newNode->prev = current->prev;
            if (current->prev) {
                current->prev->next = newNode;
            } else {
                head = newNode;
            }
            current->prev = newNode;
            ++list_size;
        }
    }

    void insert(ListIterator<T> pos, size_t count, const T& value) {
        for (size_t i = 0; i < count; ++i) {
            emplace(pos, value);
        }
    }

    void erase(ListIterator<T> pos) {
        Node<T>* current = pos.current;
        if (current) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            delete current;
            --list_size;
        }
    }

    void swap(List& other) {
        std::swap(head, other.head);
        std::swap(tail, other.tail);
        std::swap(list_size, other.list_size);
    }

    void resize(size_t count, const T& value = T()) {
        while (list_size < count) {
            push_back(value);
        }
        while (list_size > count) {
            pop_back();
        }
    }

    void clear() {
        while (!empty()) {
            pop_back();
        }
    }

    // Operations methods
    void splice(ListIterator<T> pos, List& other) {
        if (!other.empty()) {
            Node<T>* otherHead = other.head;
            Node<T>* otherTail = other.tail;
            other.head = other.tail = nullptr;
            other.list_size = 0;

            if (pos.current) {
                Node<T>* current = pos.current;
                Node<T>* prevNode = current->prev;
                if (prevNode) {
                    prevNode->next = otherHead;
                    otherHead->prev = prevNode;
                } else {
                    head = otherHead;
                }
                current->prev = otherTail;
                otherTail->next = current;
            } else {
                if (tail) {
                    tail->next = otherHead;
                    otherHead->prev = tail;
                } else {
                    head = otherHead;
                }
                tail = otherTail;
            }
            list_size += other.size();
        }
    }

    void remove(const T& value) {
        Node<T>* current = head;
        while (current) {
            Node<T>* nextNode = current->next;
            if (current->data == value) {
                erase(ListIterator<T>(current));
            }
            current = nextNode;
        }
    }

    template <typename UnaryPredicate>
    void remove_if(UnaryPredicate p) {
        Node<T>* current = head;
        while (current) {
            Node<T>* nextNode = current->next;
            if (p(current->data)) {
                erase(ListIterator<T>(current));
            }
            current = nextNode;
        }
    }

    void unique() {
        Node<T>* current = head;
        while (current && current->next) {
            if (current->data == current->next->data) {
                erase(ListIterator<T>(current->next));
            } else {
                current = current->next;
            }
        }
    }

    void merge(List& other) {
        List merged;
        while (!empty() && !other.empty()) {
            if (front() <= other.front()) {
                merged.push_back(front());
                pop_front();
            } else {
                merged.push_back(other.front());
                other.pop_front();
            }
        }
        while (!empty()) {
            merged.push_back(front());
            pop_front();
        }
        while (!other.empty()) {
            merged.push_back(other.front());
            other.pop_front();
        }
        swap(merged);
    }

    void sort() {
        if (size() > 1) {
            List left, right;
            ListIterator<T> middle = begin();
            size_t half_size = size() / 2;

            for (size_t i = 0; i < half_size; ++i) {
                left.push_back(*middle);
                ++middle;
            }
            while (middle != end()) {
                right.push_back(*middle);
                ++middle;
            }

            left.sort();
            right.sort();
            merge(left, right);
        }
    }

    void reverse() {
        ListIterator<T> current = begin();
        while (current != end()) {
            Node<T>* temp = current.current->next;
            current.current->next = current.current->prev;
            current.current->prev = temp;
            current.current = temp;
        }
        std::swap(head, tail);
    }
};

// Example usage
int main() {
    List<int> myList;

    // Testing various methods
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    std::cout << "List size: " << myList.size() << std::endl;

    myList.pop_back();

    std::cout << "List size after pop_back: " << myList.size() << std::endl;

    myList.push_front(0);

    std::cout << "List front after push_front: " << myList.front() << std::endl;

    myList.emplace_back(4);

    std::cout << "List back after emplace_back: " << myList.back() << std::endl;

    myList.emplace(ListIterator<int>(myList.begin()), 2, 5);

    std::cout << "List size after emplace: " << myList.size() << std::endl;

    myList.erase(ListIterator<int>(myList.begin()));

    std::cout << "List size after erase: " << myList.size() << std::endl;

    myList.merge(myList);

    std::cout << "List size after merge: " << myList.size() << std::endl;

    myList.sort();

    std::cout << "List front after sort: " << myList.front() << std::endl;

    myList.reverse();

    std::cout << "List front after reverse: " << myList.front() << std::endl;

    return 0;
}
