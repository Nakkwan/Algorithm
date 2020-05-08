#pragma once

#include "pch.h"

template <typename T>
class SortedLinkedList;

template <typename T>
class SortedIterator;

template <typename T>
class UnsortedLinkedList;

template <typename T>
class UnsortedIterator;

class Employee;
class EmpList;
class EmpScore;


class Base {
public:
	static EmpList Emp_List;
	static SortedLinkedList<EmpScore> E_Score;
};