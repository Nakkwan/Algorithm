#ifndef UNSORTEDLIST_H
#define UNSORTEDLIST_H
#define MAX_SIZE 5

class ArrayList {
private:
	int size;
	int current;
	int data_length;
	int* node;
public:
	ArrayList(int size);
	~ArrayList() {};

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

