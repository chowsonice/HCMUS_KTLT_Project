#pragma once
#include <iostream>
using namespace std;
template<typename T>
struct Node
{
	T data;
	Node<T>* next;

	Node<T>() : next(nullptr) {}
	Node<T>(T tdata) : data(tdata), next(nullptr) {}
	Node<T>(const Node<T>& n) : Node<T>(n.data) {}
};

//Nếu muốn khai báo một node thuộc class Student thì dùng Node<Student>* n = new Node<Student>;
//Tương tự nếu muốn node cho một course thì dùng Node<Course>* n = new Node<Course>;


//Dùng linked list cho cái gì thì LinkedList<Student> list;
//Thêm thì list.add(...)
//Xóa thì list.remove(số thứ tự, bắt đầu là 1)

template<typename T>
struct LinkedList {
	Node<T>* head;

public:
	LinkedList() : head(nullptr) {}
	LinkedList(Node<T>* nodeData) : head(new Node<T>(*nodeData)) {}
	LinkedList(const LinkedList<T> &list) : head(list.head) {}
	~LinkedList() {
		delete head;
		head = nullptr;
	}
	void add(T data);
	void remove(const int& no);
	void removeHead();
	friend ostream& operator<<(ostream& os, LinkedList<T> const &l) {
		Node<T>* cur = l.head;
		while (cur != nullptr) {
			os << cur->data << "\n";
			cur = cur->next;
		}
		return os;
	}
};

template<typename T>
void LinkedList<T>::add(T data) {
	if (!head) {
		head = new Node<T>(data);
		return;
	}
	Node<T>* cur = head;
	while (cur->next) cur = cur->next;
	cur->next = new Node<T>(data);
	return;
}

template<typename T>
void LinkedList<T>::removeHead() {
	Node<T>* cur = head;
	head = head->next;
	cur->next = nullptr;
}

template<typename T>
void LinkedList<T>::remove(const int& no) {
	// no là số thứ tự của học sinh cần xóa
	if (!head) return;

	if (no == 0) return removeHead();
	
	Node<T>* cur = head;
	int count = 0;

	while (cur->next && count+1 < no - 1) {
		cur = cur->next;
		count++;
	}

	if (!cur->next || count < no - 1) return;
	
	Node<T>* temp = cur->next;
	cur->next = temp->next;

	delete temp;
}