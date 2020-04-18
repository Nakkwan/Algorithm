#ifndef __SIMPLEITEMTYPE_H
#define __SIMPLEITEMTYPE_H
#include <string>
using namespace std;

class SimpleItemType{
private:
	int S_label;						//����� �������� ���� ��ȣ
	string S_name;						//�������� �̸�
	int S_usage;						//�������� type
public:
	SimpleItemType();					//������
	SimpleItemType(int inlabel);		//������
	~SimpleItemType() {}				//�Ҹ���

	/*
	@brief: ���� ID�� ����
	@pre: set unique ID
	@post: none
	@return: unique label
	*/
	int getLabel() const;

	/*
	@brief: ������ �̸��� ����
	@pre: set name of object
	@post: none
	@return: name of object
	*/
	string getName() const;

	/*
	@brief:	������ ������ ����
	@pre: set usage of object
	@post: none
	@rreturn: return integer correspond with usage
	*/
	int getUsage() const;

	/*
	@brief: ���� ID�� ������
	@pre: none
	@post: ���� ID�� ������
	@param: ������ ID integer
	*/
	void setLabel(int inlabel);

	/*
	@brief: ������ �̸��� ������
	@pre: none
	@post: �̸��� ������
	@param: ������ �̸�
	*/
	void setName(string inname);

	/*
	@brief: ������ �뵵�� ������
	@pre: none
	@post: ������ �뵵�� ������
	@param: ������ �뵵�� �ش��ϴ� integer
	*/
	void setUsage(int inusage);

	/*
	@brief: SimpleItemType�� member value�� ������
	@pre: none
	@post: member value�� ������
	@param: member value�� �ش��ϴ� object�� ID, name, usage
	*/
	void setRecord(int inlabel, string inname, int inusage);

	/*
	@brief: ������ ���� ID�� ����ڷκ��� �޾ƿ�
	@pre: none
	@post: �Է¿� ���� ID�� ������
	*/
	void setLabelfromKB();

	/*
	@brief: ������ �̸��� ����ڷκ��� �޾ƿ�
	@pre: none
	@post: �Է¿� ���� ������ �̸��� ������
	*/
	void setNamefromKB();

	/*
	@brief: ������ �뵵�� ����ڷκ��� �޾ƿ�
	@pre: none
	@post: �Է¿� ������ �뵵�� ������
	*/
	void setUsagefromKB();

	/*
	@brief: member value�� display
	@pre: none
	@post: none
	*/
	void DisplayItem();

	/*
	@brief: �� ��ü�� ũ�� �� operator
	@pre: ���� ��ü�� ID ����
	@post: none
	@param: ���� ��ü
	@return: ������ 1, �ٸ��� 0�� ����
	*/
	bool operator==(const SimpleItemType& data) {
		if (this->S_label == data.getLabel()) {
			return true;
		}
		else {
			return false;
		}
	}

	/*
	@brief: �� ��ü�� ũ�� �� operator
	@pre: ���� ��ü�� ID ����
	@post: none
	@param: ���� ��ü
	@return: ���� ��ü�� �� ũ�� 1, �ƴϸ� 0�� ����
	*/
	bool operator>(const SimpleItemType& data) {
		if (this->S_label > data.getLabel()) {
			return true;
		}
		else {
			return false;
		}
	}

	/*
	@brief: �� ��ü�� ũ�� �� operator
	@pre: ���� ��ü�� ID ����
	@post: none
	@param: ���� ��ü
	@return: ���� ��ü�� �� ������ 1, �ƴϸ� 0�� ����
	*/
	bool operator<(const SimpleItemType& data) {
		if (this->S_label < data.getLabel()) {
			return true;
		}
		else {
			return false;
		}
	}

	/*
	@brief: assign operator of member value
	@pre: set object for assign
	@post: �ش��ϴ� ������ member value�� ���� �Ҵ��
	@param: ���� �Ҵ��� ��ü
	*/
	void operator=(const SimpleItemType& data) {
		S_label = data.getLabel();
		S_name = data.getName();
		S_usage = data.getUsage();
	}
};


#endif // !
