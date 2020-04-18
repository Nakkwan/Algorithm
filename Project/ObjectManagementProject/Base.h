#pragma once

class ItemType;
class SimpleItemType;
class RoomType;
class TempList;
class RecentList;
class BestList;

template<typename T>
class LinkedQueue;

template<typename T>
class Queue;

template<typename T>
class SortedList;

template<typename T>
class Stack;

template<typename T>
class UnsortedList;

class Base {
public:
	static SortedList<ItemType> MasterList;
	static UnsortedList<RoomType> RoomList;
	static TempList T_List;
	static RecentList R_List;
	static BestList B_List;
};