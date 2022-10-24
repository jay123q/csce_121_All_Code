#include "linked_list.h"
#include <iostream>
#include <string>

using std::cout, std::endl, std::string, std::ostream;

void MyList::add(const std::string& name, int score) {
    // TODO(student)
    // check if the HEAD TBE FIRST VALUE EXISTS
    if(_head == nullptr||_size==0)
    {
        MyNode * NewOne = new MyNode(name,score);
        _head = NewOne; //  so now the head is the tail
       _tail = NewOne;// so now if the head is nuull, the tail is the sart and increase size


    }
    else
    {
        MyNode * NewOne = new MyNode(name,score);
        _tail->next=NewOne;
        _tail = NewOne;
        // _tail->next = nullptr; 
    }

    _size++;
    // MyNode * NewOne =  new MyNode(name,score); 
    // MyNode*_head->NewOne = this->_head;
}

void MyList::clear() {
    // TODO(student)
    // MyNode
    while(_head!=nullptr)
    {
        _tail=_head;
        _head=_head->next;
        delete _tail;
    }
    _size=0;
}

bool MyList::remove(const std::string& name) {
    // TODO(student)
    return false;
}

bool MyList::insert(const std::string& name, int score, size_t index) {
    // TODO(student)
    return false;
}

MyList::MyList()
  : _size(0), _head(nullptr), _tail(nullptr) { }

MyList::~MyList() {
    clear();
}

size_t MyList::size() const {
    return _size;
}

bool MyList::empty() const {
    return _head == nullptr;
}

MyNode* MyList::head() const {
    return _head;
}

ostream& operator<<(ostream& os, const MyList& myList) {
    MyNode* _current = myList.head();
    if (_current == nullptr) {
        os << "<empty>" << endl;
        return os;
    }

    os << "[ " << _current->name << ", " << _current->score << " ]";
    _current = _current->next;
    while (_current != nullptr) {
        os << " --> [ " << _current->name << ", " << _current->score << " ]";
        _current = _current->next;
    }
    
    return os;
}

MyNode::MyNode(const std::string& name, int score)
    : name{name}, score{score}, next{nullptr}, prev{nullptr} {}
