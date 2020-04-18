#ifndef __CONTAINERTYPE_H
#define __CONTAINERTYPE_H

#include "SimpleItemType.h"
#include "UnsortedList.h"
#include "Base.h"

class ContainerType : public Base {
private:
	int C_ID;				//container�� ID
	string C_Type;			//container�� ����
	string C_loc;			//container�� ��ġ
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
	@brief: Container�� ��ġ �� �ޱ�
	@pre: Container�� ��ġ�� �����Ǿ� �־����
	@post: none
	@return: Container Location return
	*/
	string GetContainerLocation() const;

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
	@brief: Container��  ��ġ ����
	@pre: none
	@post: Container�� ��ġ�� ������
	@param: ������ Container ��ġ string
	*/
	void SetContainerLocation(string inLoc);

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
	void SetContainerRecord(int inID, string inLoc, string inType);


	/*
	@brief: ContainerID�� ����ڷκ��� �Է¹���
	@pre: none
	@post: ContainerID�� ����ڷκ��� �Է¹��� ������ ������ (10~99)
	*/
	void SetContainerIDfromKB();

	/*
	@brief: Container�� ��ġ�� ����ڷκ��� �Է¹���
	@pre: none
	@post: Container�� ��ġ���� ����ڷκ��� ����
	*/
	void SetContainerLocationfromKB();

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
	void DiplayAllItem();

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


	/*
	@brief: Container�� �ִ� ������ ID�� �˻���
	@pre: ã�� ������ �����ؾ� ��
	@post: �ش��ϴ� ������ ������ ������ ȭ�鿡 Display��
	@return: ������ ã���� 1, ��ã���� 0�� return ��
	*/
	int FindByID(SimpleItemType& data);

	/*
	@brief: Container�� �ִ� ������ �̸����� �˻���
	@pre: ã�� ������ �����ؾ� ��
	@post: �ش��ϴ� ������ ������ ������ ȭ�鿡 Display��
	@return: ������ ã���� 1, ��ã���� 0�� return ��
	*/
	int FindByName(SimpleItemType& data);

	/*
	@brief: Container�� �ִ� ������ �뵵�� �˻���
	@pre: ã�� ������ �����ؾ� ��
	@post: �ش��ϴ� ������ ������ ������ ȭ�鿡 Display��
	@return: ������ ã���� 1, ��ã���� 0�� return ��
	*/
	int FindByUsage(SimpleItemType& data);

	/*
	@brief: ItemList�� �ִ� ������ index�� �˻���
	@pre: index�� List�� ���� ���� �־����
	@post: �ش��ϴ� ������ reference�� ��ȯ��
	*/
	void GetItemByIndex(SimpleItemType& data, int idx) const;

	/*
	@brief: PhotoList�� �ִ� ������ ��θ� index�� �˻���
	@pre: index�� List�� ���� ���� �־����
	@post: �ش��ϴ� ��ΰ� reference�� ��ȯ��
	*/
	void GetPhotoByIndex(string& data, int idx) const;


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
		C_Type = data.GetContainerType();
		C_loc = data.GetContainerLocation();
		numOfPhoto = data.GetNumOfPhoto();
		numOfitem = data.GetNumOfItem();

		SimpleItemType tempItem;				//ItemList�� �Ҵ����
		ItemList.MakeEmpty();
		for (int i = 0; i < numOfitem; i++) {
			data.GetItemByIndex(tempItem, i);
			ItemList.Add(tempItem);
		}

		string tempStr;							//������ ��θ� �Ҵ����
		photoList.MakeEmpty();
		for (int i = 0; i < numOfPhoto; i++) {
			data.GetPhotoByIndex(tempStr, i);
			photoList.Add(tempStr);
		}
	}
};


#endif // !__CONTAINERTYPE_H
