#ifndef LIBOPENSPOTIFY_HASH_H
#define LIBOPENSPOTIFY_HASH_H

struct hashentry {
	void *key;
	void *value;
	unsigned int hash;
	struct hashentry *next;
};

struct hashtable {
	int size;
	int keysize;
	int count;
	struct hashentry **entries;
};

struct hashiterator {
	int offset;
	struct hashentry *entry;
	struct hashtable *hashtable;
};

struct hashtable *hashtable_create(int keysize);
void hashtable_insert(struct hashtable *hashtable, void *key, void *value);
void *hashtable_find(struct hashtable *hashtable, void *key);
void hashtable_insert(struct hashtable *hashtable, void *key, void *value);
struct hashiterator *hashtable_iterate_init(struct hashtable *hashtable);
struct hashentry *hashtable_iterate_next(struct hashiterator *iter);
void hashtable_iterate_free(struct hashiterator *iter);
void hashtable_free(struct hashtable *hashtable);

#endif
