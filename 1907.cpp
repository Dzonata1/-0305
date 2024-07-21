#include <iostream>
#include <string>

using namespace std;


template <typename T>
struct Node{
    public:
    T data;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
    Node(T data,  Node<T>* next, Node<T>* prev){
        this->data=data;
        this->next=next;
        this->prev=prev;
    }

};

template<typename T>
class List {

    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int size = 0;

public:
    void show(){
        Node<T>* iterator = head;
        for (int i = 0; i < size; i++){
            cout << iterator->data;
            iterator = iterator -> next;
        } 
    }

    void push_front(T data){
        Node<T>* newNode = new Node<T>(data, head, nullptr);
        if (head != nullptr){
            head ->prev = newNode;
        }
        head = newNode;
        if (tail == nullptr)
            tail = newNode;
        
        size++;
    }

    void push_back(T data){
        Node<T>* newNode = new Node<T>(data, nullptr, tail);
        if (tail != nullptr){
            tail -> next = newNode;
        }
        tail = newNode;
        if (head == nullptr){
            head = newNode;
        }
        size++;
    }
    void insert(T data, int index) {
        if (index < 0 || index > size) {
            return;
        }
        if (index == 0) {
            push_front(data); // Вставка в начало
            return;
        }
        if (index == size) {
            push_back(data); // Вставка в конец
            return;
        }

        if (index < size / 2) {
            // Если индекс ближе к началу списка
            Node<T>* iterator = head;
            for (int i = 0; i < index - 1; i++) {
                iterator = iterator->next;
            }
            Node<T>* newNode = new Node<T>(data, iterator->next, iterator);
            iterator->next->prev = newNode;
            iterator->next = newNode;
        } else {
            // Если индекс ближе к концу списка
            Node<T>* iterator = tail;
            for (int i = size - 1; i > index; i--) {
                iterator = iterator->prev;
            }
            Node<T>* newNode = new Node<T>(data, iterator, iterator->prev);
            iterator->prev->next = newNode;
            iterator->prev = newNode;
        }
        size++;

    
    }

    void delet_front(){
        if (head == nullptr)
            return;
        Node<T>* temp = head;
        head =head -> next;
        if (head !=nullptr){
            head ->prev =nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
        size--;

    }

    void delete_back() {
        if (tail == nullptr) 
            return;
        Node<T>* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } 
        else {
            head = nullptr;
        }
        delete temp;
        size--;
    }

   void delete_at(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        if (index == 0) {
            delet_front(); 
            return;
        }
        if (index == size - 1) {
            delete_back(); 
            return;
        }

        if (index < size / 2) {
            
            Node<T>* iterator = head;
            for (int i = 0; i < index; i++) {
                iterator = iterator->next;
            }
            iterator->prev->next = iterator->next;
            iterator->next->prev = iterator->prev;
            delete iterator;
        } else {
            
            Node<T>* iterator = tail;
            for (int i = size - 1; i > index; i--) {
                iterator = iterator->prev;
            }
            iterator->prev->next = iterator->next;
            iterator->next->prev = iterator->prev;
            delete iterator;
        }
        size--;
    } 

}; 




  int main(){
List <int> list;
list.push_front(4);
list.push_front(5);
list.push_front(4);
list.push_front(0);
list.push_back(6);
list.insert(5,6);
list.show();
return 0;

  }  





  





   