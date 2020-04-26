#ifndef __DRAWERTYPE_H
#define __DRAWERTYPE_H


#include "Base.h"
#include "Stack.h"
#include "ContainerType.h"
#include "SingleLinkedList.h"
#include <string>
using namespace std;

class DrawerType : public Base{
private:
	int d_ID;
	string d_Name;
	string d_type;
	int d_length;
	int d_curPointer;
	SingleLinkedList<ContainerType> d_Array;
public:
	/*
	@brief: Drawer�� ���� ID �� �ޱ�
	@pre: DrawerID�� �����Ǿ� �־����
	@post: none
	@return: DrawerID return
	*/
	int GetDrawerID() const;

	/*
	@brief: Drawer�� ���� ID �� �ޱ�
	@pre: DrawerID�� �����Ǿ� �־����
	@post: none
	@return: DrawerID return
	*/
	string GetDrawerName() const;

	/*
	@brief: Drawer�� ���� �� �ޱ�
	@pre: Drawer�� ������ �����Ǿ� �־����
	@post: none
	@return: Drawer Type return
	*/
	string GetDrawerType() const;

	/*
	@brief: Drawer�� �ִ� Container ���� �ޱ�
	@pre: none
	@post: none
	@return: Drawer�� Container�� ���� return
	*/
	int GetNumOfContainer() const;

	/*
	@brief: DrawerID ����
	@pre: none
	@post: DrawerID ���� ������
	@param: ������ DrawerID integer
	*/
	void SetDrawerID(int inID);

	/*
	@brief: Drawer��  ���� ����
	@pre: none
	@post: Drawer�� ������ ������
	@param: ������ Drawer ���� string
	*/
	void SetDrawerName(string inName);

	/*
	@brief: Drawer��  ���� ����
	@pre: none
	@post: Drawer�� ������ ������
	@param: ������ Drawer ���� string
	*/
	void SetDrawerType(string inType);

	/*
	@brief: Drawer�� ���� ����
	@pre: none
	@post: Drawer�� ID, ������ ������
	@param: ������ Drawer�� ID(int), Type(string)
	*/
	void SetDrawerRecord(int inID, string inName, string inType);

	/*
	@brief: DrawerID�� ����ڷκ��� �Է¹���
	@pre: none
	@post: DrawerID�� ����ڷκ��� �Է¹��� ������ ������ (10~99)
	*/
	void SetDrawerIDfromKB();

	/*
	@brief: Drawer�� ������ ����ڷκ��� �Է¹���
	@pre: none
	@post: Drawer�� ������ ����ڷκ��� ����
	*/
	void SetDrawerNamefromKB();

	/*
	@brief: Drawer�� ������ ����ڷκ��� �Է¹���
	@pre: none
	@post: Drawer�� ������ ����ڷκ��� ����
	*/
	void SetDrawerTypefromKB();

	/*
	@brief: Drawer�� Container�� �߰�
	@pre: Container ������ �����Ǿ� �־�� ��
	@post: Drawer�� ContainerList�� Container�� �߰���.
	@param: ContainerType for add
	*/
	void AddContainer(const ContainerType& data);

	/*
	@brief: Drawer���� Container�� ��
	@pre: �� Container�� ID�� �����Ǿ� �־�� ��
	@post: Drawer�� ContainerList���� �ش��ϴ� Container�� ������.
	@param: ContainerType for delete
	*/
	void DeleteContainer(ContainerType& data);

	/*
	@brief: Drawer�� Container ������ ������
	@pre: ������ Container�� ������ �����Ǿ� �־�� ��
	@post: Drawer�� ContainerList���� �ش��ϴ� Container�� ������ ���ŵ�.
	@param: ContainerType for update
	*/
	void UpdateContainer(ContainerType& data);

	/*
	@brief: ContainerList�� �ִ� Container�� ��� display��
	@pre: none
	@post: ContainerList�� �ִ� Container�� ������ ȭ�鿡 ��� display��
	*/
	void DisplayAllContainer();

	/*
	@brief: Drawer�� ������ ��� display
	@pre: none
	@post: none
	*/
	void DisplayInfo();

	void ResetList();

	int GetNextContainer(ContainerType& data);

	void MakeEmpty();
};

#endif // !__DRAWERTYPE_H
