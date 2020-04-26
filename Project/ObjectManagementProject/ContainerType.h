#ifndef __CONTAINERTYPE_H
#define __CONTAINERTYPE_H

#include "SimpleItemType.h"
#include "UnsortedList.h"
#include "Base.h"

class ContainerType : public Base {
private:
	int C_ID;				//container�� ID
	string C_Name;
	string C_Type;			//container�� ����
	int numOfPhoto;
	int numOfitem;
	UnsortedList<string> photoList;			//container�� ������ ��� List
	UnsortedList<SimpleItemType> ItemList;	//Container�� ��� �ִ� ���� List
public:
	ContainerType();				//������
	~ContainerType() {}				//�Ҹ���

	/*
	@brief: Container�� ���� ID �� �ޱ�
	@pre: ContainerID�� �����Ǿ� �־����
	@post: none
	@return: ContainerID return
	*/
	int GetContainerID() const;

	/*
	@brief: Container�� ���� �� �ޱ�
	@pre: Container�� ������ �����Ǿ� �־����
	@post: none
	@return: Container Type return
	*/
	string GetContainerName() const;

	/*
	@brief: Container�� ���� �� �ޱ�
	@pre: Container�� ������ �����Ǿ� �־����
	@post: none
	@return: Container Type return
	*/
	string GetContainerType() const;

	/*
	@brief: Container�� ����ִ� ���� ���� �ޱ�
	@pre: none
	@post: none
	@return: Container�� ��� ������ ���� return
	*/
	int GetNumOfItem() const;

	/*
	@brief: Container�� ���� ���� �ޱ�
	@pre: none
	@post: none
	@return: Container�� ���� ������ ���� return
	*/
	int GetNumOfPhoto() const;

	/*
	@brief: ContainerID ����
	@pre: none
	@post: ContainerID ���� ������
	@param: ������ ContainerID integer
	*/
	void SetContainerID(int inID);

	/*
	@brief: Container��  �̸� ����
	@pre: none
	@post: Container�� �̸��� ������
	@param: ������ Container �̸� string
	*/
	void SetContainerName(string inName);

	/*
	@brief: Container��  ���� ����
	@pre: none
	@post: Container�� ������ ������
	@param: ������ Container ���� string
	*/
	void SetContainerType(string inType);

	/*
	@brief: Container�� ���� ����
	@pre: none
	@post: container�� ID, ��ġ, ������ ������
	@param: ������ Container�� ID(int), Location(string), Type(string)
	*/
	void SetContainerRecord(int inID, string inName, string inType);

	/*
	@brief: Container�� ������ ����ڷκ��� �Է¹���
	@pre: none
	@post: Container�� ������ ����ڷκ��� ����
	*/
	void SetContainerIDfromKB();

	/*
	@brief: Container�� ������ ����ڷκ��� �Է¹���
	@pre: none
	@post: Container�� ������ ����ڷκ��� ����
	*/
	void SetContainerNamefromKB();

	/*
	@brief: Container�� ������ ����ڷκ��� �Է¹���
	@pre: none
	@post: Container�� ������ ����ڷκ��� ����
	*/
	void SetContainerTypefromKB();

	/*
	@brief: Container�� ������ ����ڷκ��� �Է¹���
	@pre: none
	@post: Container�� ID, Location, Type�� ����ڷκ��� �Է¹���
	*/
	void SetContainerRecordfromKB();

	/*
	@brief: Container�� ������ ����
	@pre: ���� ������ ������ �����Ǿ� �־�� ��
	@post: Container�� ItemList�� ������ �߰���.
	@param: ��⿡ ���� ���� (SimpleItemType)
	*/
	void AddItem(const SimpleItemType& data);

	/*
	@brief: Container���� ������ ��
	@pre: �� ������ ID�� �����Ǿ� �־�� ��
	@post: Container�� ItemList���� �ش��ϴ� ������ ������.
	@param: ��⿡�� �� ���� (SimpleItemType)
	*/
	void DeleteItem(SimpleItemType& data);

	/*
	@brief: Container�� ��� ������ ������ ������
	@pre: ������ ������ ������ �����Ǿ� �־�� ��
	@post: Container�� ItemList���� �ش��ϴ� ������ ������ ���ŵ�.
	@param: ��⿡�� ������ ���� (SimpleItemType)
	*/
	void UpdateItem(SimpleItemType data);


	/*
	@brief: ����� ������ �ִ� ��θ� �߰���
	@pre: �ش� ContainerID�� �����Ǿ� �־���ϰ� container�� ���� ������ �־����
	@post: Container�� ������ ���� ��ΰ� PhotoList�� �߰���
	@param: ������ �ִ� ��θ� ��Ÿ���� string
	*/
	void AddPhoto(string pho);

	/*
	@brief: ����� ������ �ִ� ��θ� ������
	@pre: �ش��ϴ� ������ ContainerID�� ��ΰ� �����ؾ� ��
	@post: Container�� ������ ���� ��ΰ� PhotoList���� ������
	@param: ������ ������ �ִ� ��θ� ��Ÿ���� string
	*/
	void DeletePhoto(string pho);

	/*
	@brief: ����� ������ �ִ� ��θ� ������
	@pre: �ش��ϴ� ������ ��ο� �ش� ContainerID�� �����ؾ� ��
	@post: Container�� ������ ���� ��ΰ� PhotoList���� ���ŵ�
	@param: ������ ������ �ִ� ��θ� ��Ÿ���� string
	*/
	void UpdatePhoto(string pho);

	/*
	@brief: ItemList�� �ִ� ������ ��� display��
	@pre: none
	@post: ItemList�� �ִ� ������ ������ ȭ�鿡 ��� display��
	*/
	void DisplayAllItem();

	/*
	@brief: PhotoList�� �ִ� Container�� ������ ��� display��
	@pre: none
	@post: PhotoList�� �ִ� Container�� ������ ��ΰ� ��� display��
	*/
	void DisplayAllPhoto();

	/*
	@brief: Container�� ������, ��� ����, ������ ��ΰ� ��� ȭ�鿡 Display��
	@pre: none
	@post: Container�� ������, ��� ����, ������ ��ΰ� ��� ȭ�鿡 Display��
	*/
	void DisplayContainer();

	void MakeConatinerEmpty();

	/*
	@brief: Container�� ������ ����
	@pre: ContainerID�� ������ �Ǿ��־����
	@post: none
	@return: ContainerID�� ������ 1, �ٸ��� 0�� return
	*/
	bool operator==(const ContainerType& data) {
		if (C_ID == data.GetContainerID()) {
			return true;
		}
		else {
			return false;
		}
	}

	/*
	@brief: Container ��
	@pre: ���� Container�� ID�� �����Ǿ� �־�� ��
	@post: none
	@return: ���� ContainerID�� �� ũ�� 1, ������ 0�� return��
	*/
	bool operator>(const ContainerType& data) {
		if (C_ID > data.GetContainerID()) {
			return true;
		}
		else {
			return false;
		}
	}

	/*
	@brief: Container ��
	@pre: ���� Container�� ID�� �����Ǿ� �־�� ��
	@post: none
	@return: ���� ContainerID�� �� ������ 1, ũ�� 0�� return��
	*/
	bool operator<(const ContainerType& data) {
		if (C_ID < data.GetContainerID()) {
			return true;
		}
		else {
			return false;
		}
	}

	/*
	@brief: Container�� ���� �Ҵ����
	@pre: �Ҵ��� Container�� ������ �����Ǿ� �־����
	@post: parameter�� ���� Container�� ���� Container�� ��ü��
	@param: �Ҵ��� Container
	*/
	void operator=(const ContainerType& data) {
		C_ID = data.GetContainerID();
		C_Name = data.GetContainerName();
		C_Type = data.GetContainerType();
		numOfPhoto = data.GetNumOfPhoto();
		numOfitem = data.GetNumOfItem();
		ItemList = data.ItemList;
		photoList = data.photoList;
	}
};


#endif // !__CONTAINERTYPE_H
