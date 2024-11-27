#pragma once
#include <iostream>
#include <map>
#include "BinaryTree.h"
using namespace std;
template <class K, class V>
class TreeMap {
	map<K, V> storage;
public:
	void clear();				// Removes all entries from the Map
	bool containsKey(K key);	// Returns true if this map contains a mapping for the specified key.
	V& get(K key);				// Returns the value to which the specified key is mapped, or null if this map contains no mapping for the key.
	BinaryTree<K> keySet();		// Returns a Set view of the keys contained in this map.
	void put(K key, V value);	// Associates the specified value with the specified key in this map
	int size();					// Returns the number of key-value mappings in this map
	bool removeKey(K key);		// Removes the item denoted by the given key.
	V& operator=(K key);		// Also returns the value to which the specified key is mapped, or null if this map contains no mapping for the key.
};

template <class K, class V>
void TreeMap<K, V>::clear() {
	storage.clear();
}

template <class K, class V>
bool TreeMap<K, V>::containsKey(K key) {
	return storage.find(key) != storage.end();
}

template <class K, class V>
V& TreeMap<K, V>::get(K key) {
	if (!containsKey(key)) {
		throw runtime_error("Key not found in TreeMap.");
	}
	return storage[key];
}

template <class K, class V>
BinaryTree<K> TreeMap<K, V>::keySet() {
	BinaryTree<K> keysTree;
	for (const auto& pair : storage) {
		keysTree.insert(pair.first);
	}
	return keysTree;
}

template <class K, class V>
void TreeMap<K, V>::put(K key, V value) {
	storage(key) = value;
}

template <class K, class V>
int TreeMap<K, V>::size() {
	return storage.size();
}

template <class K, class V>
bool TreeMap<K, V>::removeKey(K key) {
	return storage.erase(key) > 0;
}

template <class K, class V>
V& TreeMap<K, V>::operator=(K key){
	return get(key);
}