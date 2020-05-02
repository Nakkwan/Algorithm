#pragma once
#include "pch.h"

class ItemType;
class SimpleItemType;
class RoomType;
class TempList;
class RecentList;
class BestList;
class MasterType;
class RoomList;


template<typename T>
class Queue;

template<typename T>
class SortedList;

template<typename T>
class Stack;

template<typename T>
class UnsortedList;

template<typename T>
class DoublySortedLinkedList;

template<typename T>
class LinkedQueue;

class Base {
public:
	static MasterType Master_List;
	static RoomList Room_List;
	static TempList Temp_List;
	static RecentList Recent_List;
	static BestList Best_List;
};