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
	@brief: Drawer의 고유 ID 값 받기
	@pre: DrawerID가 설정되어 있어야함
	@post: none
	@return: DrawerID return
	*/
	int GetDrawerID() const;

	/*
	@brief: Drawer의 고유 ID 값 받기
	@pre: DrawerID가 설정되어 있어야함
	@post: none
	@return: DrawerID return
	*/
	string GetDrawerName() const;

	/*
	@brief: Drawer의 종류 값 받기
	@pre: Drawer의 종류가 설정되어 있어야함
	@post: none
	@return: Drawer Type return
	*/
	string GetDrawerType() const;

	/*
	@brief: Drawer에 있는 Container 개수 받기
	@pre: none
	@post: none
	@return: Drawer의 Container의 개수 return
	*/
	int GetNumOfContainer() const;

	/*
	@brief: DrawerID 설정
	@pre: none
	@post: DrawerID 값이 설정됨
	@param: 설정할 DrawerID integer
	*/
	void SetDrawerID(int inID);

	/*
	@brief: Drawer의  종류 설정
	@pre: none
	@post: Drawer의 종류가 설정됨
	@param: 설정할 Drawer 종류 string
	*/
	void SetDrawerName(string inName);

	/*
	@brief: Drawer의  종류 설정
	@pre: none
	@post: Drawer의 종류가 설정됨
	@param: 설정할 Drawer 종류 string
	*/
	void SetDrawerType(string inType);

	/*
	@brief: Drawer의 정보 설정
	@pre: none
	@post: Drawer의 ID, 종류가 설정됨
	@param: 설정할 Drawer의 ID(int), Type(string)
	*/
	void SetDrawerRecord(int inID, string inName, string inType);

	/*
	@brief: DrawerID를 사용자로부터 입력받음
	@pre: none
	@post: DrawerID가 사용자로부터 입력받은 값으로 설정됨 (10~99)
	*/
	void SetDrawerIDfromKB();

	/*
	@brief: Drawer의 종류를 사용자로부터 입력받음
	@pre: none
	@post: Drawer의 종류를 사용자로부터 받음
	*/
	void SetDrawerNamefromKB();

	/*
	@brief: Drawer의 종류를 사용자로부터 입력받음
	@pre: none
	@post: Drawer의 종류를 사용자로부터 받음
	*/
	void SetDrawerTypefromKB();

	/*
	@brief: Drawer에 Container를 추가
	@pre: Container 정보가 설정되어 있어야 함
	@post: Drawer의 ContainerList에 Container가 추가됨.
	@param: ContainerType for add
	*/
	void AddContainer(const ContainerType& data);

	/*
	@brief: Drawer에서 Container를 뺌
	@pre: 뺄 Container의 ID가 설정되어 있어야 함
	@post: Drawer의 ContainerList에서 해당하는 Container가 삭제됨.
	@param: ContainerType for delete
	*/
	void DeleteContainer(ContainerType& data);

	/*
	@brief: Drawer의 Container 정보를 갱신함
	@pre: 갱신할 Container의 정보가 설정되어 있어야 함
	@post: Drawer의 ContainerList에서 해당하는 Container의 정보가 갱신됨.
	@param: ContainerType for update
	*/
	void UpdateContainer(ContainerType& data);

	/*
	@brief: ContainerList에 있는 Container가 모두 display됨
	@pre: none
	@post: ContainerList에 있는 Container의 정보가 화면에 모두 display됨
	*/
	void DisplayAllContainer();

	/*
	@brief: Drawer의 정보를 모두 display
	@pre: none
	@post: none
	*/
	void DisplayInfo();

	void ResetList();

	int GetNextContainer(ContainerType& data);

	void MakeEmpty();
};

#endif // !__DRAWERTYPE_H
