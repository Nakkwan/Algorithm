#ifndef __STACK_H
#define __STACK_H

template<typename T>
class Stack {
private:
	int S_top;
	int S_size;
	int cur_Pointer;
	T* S_stack;
public:
	Stack();				//constructor
	Stack(int size);		//constructor
	~Stack();				//destructor

	/*
	@breif: ���� ����
	@pre: none
	@post: none
	*/
	void MakeEmpty();

	/*
	@breif: ������ á���� Ȯ��
	@pre: none
	@post: none
	*/
	bool IsFull();

	/*
	@breif: ������ ������� Ȯ��
	@pre: none
	@post: none
	*/
	bool IsEmpty();

	/*
	@breif: ���ÿ� element �߰�
	@pre: ���� element ����
	@post: ���ÿ� element �߰��ǰ�, ũ�� +1
	*/
	int Push(T data);

	/*
	@breif: ���ÿ��� element ����
	@pre: none
	@post: stack ���� element�� �����ǰ�, reference�� ��ȯ
	@param: element���� ���� ����
	*/
	int Pop(T& data);

	/*
	@breif: ������ ������ �ʱ�ȭ
	@pre: none
	@post: ������ pointer�� -1�� �ʱ�ȭ
	*/
	void ResetStack();

	/*
	@breif: ���� element�� ����
	@pre: none
	@post: stack�� ũ�� ������ �����͸� 1������Ű��, �ش��ϴ� element�� reference�� ����.
			������ ����� -1�� �ʱ�ȭ
	@return: ������
	*/
	int GetNextItem(T& data);

	/*
	@breif: stack���� ������ ã��
	@pre: ã�� �����͸� ����
	@post: ã�� �����͸� reference�� ��ȯ
	@param: �����͸� ���� ����
	@return: �����͸� ã���� 1, �ƴϸ� 0�� ��ȯ
	*/
	int Get(T& data);

	/*
	@breif: stack�� ������ ��ü
	@pre: ��ü�� ������ ����
	@post: �ش��ϴ� stack�� element data�� �ٲ�
	@param: �ٲ� ������
	@return: �����͸� �ٲٸ� 1, �ƴϸ� 0�� ��ȯ
	*/
	int Replace(T data);

	/*
	@breif: stack���� �����͸� ������
	@pre: ������ �� ����
	@post: �ش��ϴ� stack�� element data�� �����ǰ�, stack�� ũ�Ⱑ 1 �پ��
	@param: ������ ������
	@return: �����͸� �����ϸ� 1, �ƴϸ� 0�� ��ȯ
	*/
	int Delete(T data);

	/*
	@breif: stack�� ������ Ȯ��
	@pre: none
	@post: none
	@return: stack�� size return
	*/
	int getSize();
};
#endif