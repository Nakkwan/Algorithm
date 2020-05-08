#include "pch.h"
#include "EmpScore.h"

float EmpScore::GetScore() const {
	return S_score;
}
int EmpScore::GetRank() const {
	return S_rank;
}

void EmpScore::SetScore(float inscore) {
	S_score = inscore;
}
void EmpScore::SetRank(int inrank) {
	S_rank = inrank;
}