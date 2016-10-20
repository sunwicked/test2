//http://www.cs.uml.edu/~jlu1/doc/codes/lruCache.html
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct LRUCacheEntry
{
	int key;
	int data;
	LRUCacheEntry* prev;
	LRUCacheEntry* next;
};

class LRUCache
{
private:
	unordered_map< int, LRUCacheEntry* >	_mapping;
	vector< LRUCacheEntry* >		_freeEntries;
	LRUCacheEntry *			head;
	LRUCacheEntry *			tail;
	LRUCacheEntry *			entries;
public:
	LRUCache(size_t size){
		entries = new LRUCacheEntry[size];
		for (int i=0; i<size; i++)
			_freeEntries.push_back(entries+i);
		head = new LRUCacheEntry;
		tail = new LRUCacheEntry;
		head->prev = NULL;
		head->next = tail;
		tail->next = NULL;
		tail->prev = head;
	}
	~LRUCache()
	{
		delete head;
		delete tail;
		delete [] entries;
	}
	void set(int key, int data)
	{
		LRUCacheEntry* node = _mapping[key];
		if(node)
		{
			// refresh the link list
			detach(node);
			node->data = data;
			attach(node);
		}
		else{
			if ( _freeEntries.empty() )
			{
				node = tail->prev;
				detach(node);
				_mapping.erase(node->key);
				node->data = data;
				node->key = key;
				_mapping[key] = node;
				attach(node);
			}
			else{
				node = _freeEntries.back();
				_freeEntries.pop_back();
				node->key = key;
				node->data = data;
				_mapping[key] = node;
				attach(node);
			}
		}
	}

	int get(int key)
	{
		LRUCacheEntry* node = _mapping[key];
		if(node)
		{
			detach(node);
			attach(node);
			return node->data;
		}
		else return -1;
	}

private:
	void detach(LRUCacheEntry* node)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	void attach(LRUCacheEntry* node)
	{
		node->next = head->next;
		node->prev = head;
		head->next = node;
		node->next->prev = node;
	}
};