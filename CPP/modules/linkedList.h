// Author: http://lemming.life
// Language: C++
// Description: A simple Linked List class
// - This will handle simple types, so List<int>, List<char>, etc.

#ifndef LINKED_LIST
#define LINKED_LIST

template<class T>
struct Node {
    Node* _left;
    Node* _right;
    T _item;

    Node(const T item, Node* left) {
        _item = item;
        _left = left;
        if (left != NULL) { left->_right = this; }
        _right = NULL;
    }

    Node(T item) {
        _item = item;
    }
};

template<class T>
class List {
private:
    Node<T>* _front;
    Node<T>* _back;
    int _size;
    
public:
    List() {
        _front = NULL;
        _back = NULL;
        _size = 0;
     }

    ~List() {
        clear();
    }

    void pushBack(const T item) {
        Node<T>* node;
        if (_size == 0 ) {
            node = new Node<T>(item, NULL);
            _front = node;
            _back = node;
        } else {
            node = new Node<T>(item, _back);
            _back = node;
        }
        ++_size;
    }

    void pushFront(const T item) {
        Node<T>* node;
        if (_size == 0 ) {
            node = new Node<T>(item, NULL);
            _front = node;
            _back = node;
        } else {
            node = new Node<T>(item);
            node->_right = _front;
            _front->_left = node;
            _front = node;
        }
        ++_size;
    }

    T popBack() {
        if (_size == 0) { throw 0; }
        --_size;
        Node<T>* node = _back;
        T item = node->_item;
        if (_back->_left != NULL) { _back = _back->_left; }
        _back->_right = NULL;
        delete node;
        return item;
    }

    T popFront() {
        if (_size == 0) { throw 0; }
        --_size;

        Node<T>* node = _front;
        T item = node->_item;
        if (_front->_right != NULL) { _front = _front->_right; }
        _front->_left = NULL;
        delete node;

        return item;
    }

    T front() const { return _front->_item; }
    T back() const { return _back->_item; }

    T at(const int index) const {
        if (index < 0 || index > _size-1) { throw index; }
        
        Node<T>* node = _front;
        for(int i=0; i<_size; ++i) {
            if (i == index) {
                break;
            }
            node = node->_right;
        }

        return node->_item;
    }

    int size() const { return _size; }

    void clear() {
        if (_size == 0) { return; }

        Node<T>* node = _front;
        while (node->_right != NULL) {
            node = node->_right;
            delete node->_left;
            node->_left = NULL;
        }
        delete node;

        _front = NULL;
        _back = NULL;
        _size = 0;

    }

    List(const List& b) {
        copy(b);
    }

    List& copy(const List& b) {
        clear();
        for (int i=0; i<b.size(); ++i) {
            this->pushBack(b.at(i));
        }
        return *this;
    }
    
    List& operator=(const List& b) {
        if (this != &b) {
            copy(b);
        }
        return *this;
    }

};
#endif