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
	@brief: Score를 반환받는다.
	@pre: Set Score
	@post: none
	@return: Score(float)
	*/
	float GetScore() const;

	/*
	@brief: 등록순서를 반환받는다.
	@pre: Set Rank
	@post: none
	@return: Rank(int)
	*/
	int GetRank() const;

	/*
	@brief: 점수를 입력받는다.
	@pre: none
	@post: assign score
	@param: 고용자와 구직자의 정보로 도출한 점수
	*/
	void SetScore(float inscore);

	/*
	@brief: 등록 순위를 입력받는다.
	@pre: none
	@post: assign rank
	@param: 구직자의 등록 순위
	*/
	void SetRank(int inrank);

	/*
	@brief: 두 객체가 같은지 확인
	@pre: Set Object for compare
	@post: none
	@return: 두 객체가 같으면 1 아니면 0을 반환
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
	@brief: 두 객체의 크기를 비교
	@pre: Set Object for compare
	@post: none
	@return: 현재 객체가 더 크면 1, 아니면 0을 반환
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
	@brief: 두 객체의 크기를 비교
	@pre: Set Object for compare
	@post: none
	@return: 입력받은 객체가 더 크면 1, 아니면 0을 반환
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
	@brief: 입력받은 객체로 현재 객체를 할당
	@pre: set Object for assign
	@post: member value are assigned
	*/
	void operator=(const EmpScore& data) {
		S_rank = data.GetRank();
		S_score = data.GetScore();
	}
};