#pragma once
#include <iostream>
#include <type_traits> // for std::is_pointer
using namespace std;
template<typename T>
struct Node
{
	T data;
	Node<T>* next;

	Node<T>() : next(nullptr) {}
	Node<T>(T tdata) : data(tdata), next(nullptr) {}
	Node<T>(const Node<T>& n) : Node<T>(n.data) {}
	// Do not use remove if unsure what you are doing
	void remove() {
		if constexpr (std::is_pointer_v<T>) { // check if T is a pointer type
			delete data; // delete the data pointed to by the node
		}
	}
};


//Nhưng mà tốt nhất là không nên dùng Node<T>* gì đó
//Nên dùng thẳng LinkedList

// Khai báo thì LinkedList<Student*> list; (Nhớ là nếu list<Student*> thì 
// chuyển qua cũng phải là LinkedList<Student*>
// 
//Thêm thì {
//		Student *s = new Student();
//		s->input() nếu có, hoặc gì đó
//		list.push_back(s)
// }
// Xóa thì list.pop(k) giống như kiểu delete list[0] bình thường vậy
// Nhớ là phần tử đầu là 0
// Lấy phần tử cuối ra khỏi list (xóa và nhận) thì list.pop_back()
// Lấy phần tử đầu ra khỏi list (là xóa và nhận) thì list.pop_front()

template<typename T>
struct LinkedList {
	Node<T>* head;

public:
	LinkedList() : head(nullptr) {}
	LinkedList(Node<T>* nodeData) : head(new Node<T>(*nodeData)) {}
	LinkedList(const LinkedList<T>& list) : head(list.head) {}
	void push_back(const T data);
	void pop(const int& no);
	void remove(T data);
	void pop_back();
	void pop_front();
	void clear();

	class Iterator {
	public:
		Iterator(Node<T>* n) : current(n) {}
		Iterator& operator++() {
			current = current->next;
			return *this;
		}
		Iterator operator+(int c) {
			auto cur = begin();
			for (int i = 0; i < c; i++) {
				cur++;
			}
			return cur;
		}
		bool operator!=(const Iterator& other) const {
			return current != other.current;
		}
		T& operator*() const {
			return current->data;
		}

	private:
		Node<T>* current;
	};

	Iterator begin() const {
		return Iterator(head);
	}
	Iterator end() const {
		return Iterator(nullptr);
	}


	friend ostream& operator<<(ostream& os, LinkedList<T> const& l) {
		Node<T>* cur = l.head;
		while (cur != nullptr) {
			os << cur->data << "\n";
			cur = cur->next;
		}
		return os;
	}
	int size() const {
		int count = 0;
		Node<T>* cur = head;
		while (cur) {
			count++;
			cur = cur->next;
		}
		return count;
	}
};
template<typename T>
void LinkedList<T>::clear() {
	if (!this || !head) return;
	Node<T>* curr = head;
	while (curr) {
		Node<T>* temp = curr;
		curr = curr->next;

		if constexpr (std::is_pointer_v<T>) { // check if T is a pointer type
			delete temp->data; // delete the data pointed to by the node
		}

		delete temp; // delete the node itself
	}
	head = nullptr;
}

template<typename T>
void LinkedList<T>::push_back(const T data) {
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
void LinkedList<T>::pop_front() {
	Node<T>* cur = head;
	head = head->next;
	//delete cur;
}

template<typename T>
void LinkedList<T>::pop(const int& no) {
	//xoa phan tu thu may cua linkedlist
	if (!head) return;

	if (no == 1) {
		head = head->next;
		// head->remove();
		return;
	}

	Node<T>* cur = head;
	int count = 0;

	while (cur->next && ++count < no) cur = cur->next;
	// check if next student's number exists, and if it is the student we need to remove

	if (!cur->next) return;
	// if the next student doesn't exist (fewer than no students) 

	Node<T>* temp = cur->next;
	cur->next = temp->next;

}

template<typename T>
void LinkedList<T>::remove(T deldata) {
	if (!head) return;

	Node<T>* cur = head;

	if (head->data == deldata) {
		Node<T>* temp = head;
		head = head->next;
		// head->remove() 
		return;
	}

	while (cur->next && cur->next->data != deldata) cur = cur->next;
	
	if (!cur->next) return;

	Node<T>* temp = cur->next;
	cur->next = temp->next;

	temp->remove();
}

template<typename T>
void LinkedList<T>::pop_back() {
	//xoa phan tu cuoi cua linkedlist

	if (!head) return;

	if (head->next == nullptr) {
		// head->remove(); 
		// cannot use this remove because if you remove a student from a course, they does not get deleted completely
		head = nullptr;
		return;
	}

	Node<T>* cur = head;

	while (cur->next && cur->next->next) cur = cur->next;
	// check if last element

	Node<T>* temp = cur->next;
	cur->next = nullptr;
	
	temp->remove();
}

