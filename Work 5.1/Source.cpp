#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Stack {
public:
	Stack();
	~Stack();

	int get_size() { return size; };
	void push(T data);
	void pop();
	T top();
	bool empty();

private:

	template<typename T>
	class Element {
	public:
		Element* pNext;
		T data;

		Element(T data = T(), Element* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		};

	};
	int size;
	Element<T>* head;
};

template<typename T>
void Stack<T>::push(T data) {

	if (head == nullptr) {
		head = new Element<T>(data);
	}
	else {
		Element<T>* temp = head;
		head = new Element<T>(data, temp);
	}
	size++;
}

template<typename T>
void Stack<T>::pop() {
	if (size < 2) {
		delete head;
	}
	else {
		Element<T>* temp = head;
		head = head->pNext;
		delete temp;
	}
	size--;
}

template<typename T>
T Stack<T>::top() {
	if (size > 0) {
		return head->data;
	}

	return T();
}

template<typename T>
bool Stack<T>::empty() {
	return size > 0;
}

template<typename T>
Stack<T>::Stack() {
	size = 0;
	head = nullptr;
}

template<typename T>
Stack<T>::~Stack() {
	for (int i = 0; i < get_size(); i++) {
		pop();
	}
}


int main() {
	srand(time(NULL));
	Stack<int> p1;
	Stack<int> p2;
	string msg = "";
	int i2; int size2, int input;

	cout << "Input size P1: ";
	cin >> size2;
	cout << "Input elements: ";
	//for (int i2 = 0; i2 < size2; i2++) {
	//	cin >> input;
	//	p1.push(input);
	//}

	int size = p1.get_size();
	for (int i = 0; i < size; i++) { 
		if (p1.top() % 2 == 0 and p1.top() != 0) { 
			break; 
		}
		else {
			p2.push(p1.top()); 
			p1.pop(); 
		}
	}
	 
	int sizeP1 = p1.get_size(); 
	msg += "P1 = ";
	for (int i = 0; i < sizeP1; i++) { 
		msg += to_string(p1.top()) + " "; 
		p1.pop(); 
	}

	int sizeP2 = p2.get_size();
	msg += "\nP2 = ";
	for (int i = 0; i < sizeP2; i++) {  
		msg += to_string(p2.top()) + " "; 
		p2.pop(); 
	} 

	cout << msg;


	return 0;
}