#pragma once

#include "pch.h"
using namespace std;

class EmpScore {
private:
	int S_rank;
	float S_score;

public:
	EmpScore() {
		S_rank = -1;
		S_score = -1;
	}
	~EmpScore(){}

	/*
	@brief: Score�� ��ȯ�޴´�.
	@pre: Set Score
	@post: none
	@return: Score(float)
	*/
	float GetScore() const;

	/*
	@brief: ��ϼ����� ��ȯ�޴´�.
	@pre: Set Rank
	@post: none
	@return: Rank(int)
	*/
	int GetRank() const;

	/*
	@brief: ������ �Է¹޴´�.
	@pre: none
	@post: assign score
	@param: ����ڿ� �������� ������ ������ ����
	*/
	void SetScore(float inscore);

	/*
	@brief: ��� ������ �Է¹޴´�.
	@pre: none
	@post: assign rank
	@param: �������� ��� ����
	*/
	void SetRank(int inrank);

	/*
	@brief: �� ��ü�� ������ Ȯ��
	@pre: Set Object for compare
	@post: none
	@return: �� ��ü�� ������ 1 �ƴϸ� 0�� ��ȯ
	*/
	bool operator==(const EmpScore& data) {
		if (S_score == data.GetScore()) {
			return true;
		}
		else {
			return false;
		}
	}

	/*
	@brief: �� ��ü�� ũ�⸦ ��
	@pre: Set Object for compare
	@post: none
	@return: ���� ��ü�� �� ũ�� 1, �ƴϸ� 0�� ��ȯ
	*/
	bool operator>(const EmpScore& data) {
		if (S_score > data.GetScore()) {
			return true;
		}
		else {
			return false;
		}
	}

	/*
	@brief: �� ��ü�� ũ�⸦ ��
	@pre: Set Object for compare
	@post: none
	@return: �Է¹��� ��ü�� �� ũ�� 1, �ƴϸ� 0�� ��ȯ
	*/
	bool operator<(const EmpScore& data) {
		if (S_score < data.GetScore()) {
			return true;
		}
		else {
			return false;
		}
	}

	/*
	@brief: �Է¹��� ��ü�� ���� ��ü�� �Ҵ�
	@pre: set Object for assign
	@post: member value are assigned
	*/
	void operator=(const EmpScore& data) {
		S_rank = data.GetRank();
		S_score = data.GetScore();
	}
};