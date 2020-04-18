#ifndef __QUEUE_H
#define __QUEUE_H

template<typename T>
class Queue {
private:
	int Q_head;
	int Q_tail;
	int Q_size;					//�����Ͱ� �� �� �ִ� ��ü queue�� ũ��, ��ü �Ҵ�� ũ��� Q_size + 1�̴�.
	int Q_curSize;				//���� ����� �͵��� ũ��
	int Q_curPointer;			//������
	T* Q_item;

public:
	Queue();					//������
	Queue(int size);			//������
	~Queue();					//�Ҹ���

	/*
	@brief: queue �ʱ�ȭ
	@pre: none
	@post: queue�� ũ�Ⱑ 0�� �ǰ�, head�� tail�� �ʱ�ȭ ��
	*/
	void MakeEmpty();

	/*
	@brief: queue�� �� á���� ����
	@pre: none
	@post: none
	*/
	bool IsFull();

	/*
	@brief: queue�� ������� ����
	@pre: none
	@post: none
	*/
	bool IsEmpty();

	/*
	@brief: queue�� ������ �߰�
	@pre: �߰��� ������ ����
	@post: queue�� �����Ͱ� �߰��ǰ� ũ�Ⱑ 1 �þ. head�� ���� ĭ���� �̵�
	@return: �߰��� �Ǹ� 1, �ȵǸ� 0 return
	*/
	int Enqueue(T data);

	/*
	@brief: queue�� ���� ���� ������ ����
	@pre: none
	@post: queue�� �����Ͱ� �����ǰ� ũ�Ⱑ 1 �پ��. tail�� ���� ĭ���� �̵�. ������ �����͸� reference�� ��ȯ
	@param: ������ �����͸� reference�� ���� ����
	@return: ������ �Ǹ� 1, �ȵǸ� 0 return
	*/
	int Dequeue(T& data);

	/*
	@brief: queue�� ������ Ȯ��
	@pre: none
	@post: none
	*/
	int GetSize();

	/*
	@brief: queue�� ������ ����
	@pre: none
	@post: queue�� �����Ͱ� tail�� ���� �ʱ�ȭ ��
	*/
	void ResetQueue();

	/*
	@brief: ���� �����Ϳ� �ش��ϴ� ������, pointer ��ȯ
	@pre: none
	@post: �����Ͱ� 1�þ�� �׿� �ش��ϴ� �����Ͱ� return ��
	@param: �����͸� ���� ����
	@return: pointer return
	*/
	int GetNextItem(T& data);

	/*
	@brief: �����͸� ã��
	@pre: ã�� ������ ����
	@post: �ش��ϴ� �����Ͱ� reference�� ��ȯ ��
	@param: ��ȯ ���� ����
	@return: �����͸� ã���� 1, �ƴϸ� 0�� return
	*/
	int Get(T& data);

	/*
	@brief: �ش��ϴ� ������ ����
	@pre: ������ ������ ����
	@post: �ش��ϴ� �����Ͱ� �����ǰ�, queue�� �����ĵ�
	@param: ������ �������� ������ ��� ����
	@return: ������ �Ǹ� 1 �ƴϸ� 0�� return
	*/
	int Delete(const T& data);

	/*
	@brief: queue�� element�� ��ü
	@pre: ��ü�� ������ ����
	@post: �ش��ϴ� element�� �����Ͱ� ��ü��
	@param: ��ü�� ������
	@return: �����Ͱ� ��ü�Ǹ� 1, �ƴϸ� 0�� return
	*/
	int Replace(T data);
};
#endif