#ifndef UNSORTEDLIST_H
#define UNSORTEDLIST_H
#define MAX_SIZE 1000

class Unsortedlist {
private:
	int size;
	int current;
	int data_length;
	int* node;
public:
	Unsortedlist(int size);
	~Unsortedlist() {};

	void Add(int val);
	void Delete(int val);
	void MakeEmpty();
	int Lengthls();
	bool IsFull();
	int GetNextItem();
	int RetrieveItem(int val);
	void Display();
	void replace(int index, int value);

};

#endif
