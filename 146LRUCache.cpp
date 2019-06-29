#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

template <typename K, typename V>
class Node {
public:
	K key;
	V value;
	Node* prev;
	Node* next;
	Node(K k, V v, Node* p=NULL, Node* n=NULL) {
		this->key = k;
		this->value = v;
		this->prev = p;
		this->next = n;
	}
};

template <typename K, typename V>
class NodeDoubleLinkedList {
private:
	Node<K,V>* head;
	Node<K,V>* tail;

public:
	NodeDoubleLinkedList(Node<K,V>* h = NULL, Node<K,V>* t = NULL) {
		this->head = h;
		this->tail = t;
	}

	bool addNode(Node<K,V>* n) {
		if (n == NULL)
			return false;

		if (this->head == NULL) {
			this->head = n;
			this->tail = n;
		}
		else {
			this->tail->next = n;
			n->prev = this->tail;
			this->tail = n;
		}

		return true;
	}

	// update the frequency
	bool moveNodeToTail(Node<K,V>* node) {
		if (!node)
			return false;
	
		if (this->tail == node)
			return true;

		if (this->head == node) {
			node->next->prev = NULL;
			this->head = node->next;
		}
		else {
			node->next->prev = node->prev;
			node->prev->next = node->next;
		}
		node->prev = this->tail;
		node->next = NULL;
		this->tail->next = node;
		this->tail = node;
	}

	// Remove the least used one
	Node<K,V>* removeHead() {
		if (!this->head)
			return NULL;
		
		Node<K,V>* res = this->head;
		if (this->head == this->tail) {
			this->head = NULL;
			this->tail = NULL;
		}
		else {
			this->head = this->head->next;
			this->head->prev = NULL;
		}
		return res;	// return this address and delete it later
	}
};


template <typename K, typename V>
class LRUCache {
private:
	map<K, Node<K,V>*> keyMap;
	NodeDoubleLinkedList<K, V> dataList;
	unsigned int capacity;

public:	
	LRUCache(unsigned int c) {
		if (c < 1) {
			throw "capacity should be more than 0";
		}
		this->capacity = c;
	}
	
	bool set(K key, V value) {
		typename map<K, Node<K,V>*>::iterator iter = keyMap.begin();
		iter = keyMap.find(key);
		if (iter != keyMap.end()) {
			iter->second->value = value;
			this->dataList.moveNodeToTail(iter->second);
			return true;
		}
		else {
			Node<K,V>* newNode = new Node<K,V>(key, value);
			keyMap.insert(map<K, Node<K,V>*>::value_type(key, newNode));
			this->dataList.addNode(newNode);
			if (this->keyMap.size() == this->capacity + 1) {
				this->removeMostUnusedCache();
			}
			return true;
		}
	}

	V get(K key) {
		typename map<K, Node<K,V>*>::iterator iter = keyMap.begin();
		iter = keyMap.find(key);
		if (iter != keyMap.end()) {
			Node<K,V>* res = iter->second;
			this->dataList.moveNodeToTail(res);
			return res->value;
		}
		return NULL;
	}

	void removeMostUnusedCache() {
		Node<K,V>* removedNode = this->dataList.removeHead();
		this->keyMap.erase(removedNode->key);
		delete removedNode;
	}

};


int main() {
	LRUCache<string, int> testCache(3);
	testCache.set("A", 1);
	testCache.set("B", 2);
	testCache.set("C", 3);
	cout << testCache.get("B") << endl;
	cout << testCache.get("C") << endl;
	testCache.set("D", 4);
	cout << "A ? " << testCache.get("A") << endl;


	return 0;
}