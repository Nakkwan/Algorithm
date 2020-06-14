#include <iostream>
#include "LinkedQueue.h"
#include "LinkedQueueIterator.h"
#include "DoublyLinkedList.h"
#include "DoublyIterator.h"
#include <list>
#include <string>
#include <conio.h>
#include <Windows.h>
using namespace std;

int Header_num;
int	Block_num;
int FreeList_num;

struct Block {							//Buffer의 구조체
	int num;
	bool free = false;
	bool delay = false;
	Block() {
		num = -1;
	}

	Block(int n) {
		num = n;
	}
	string Display() {
		if (delay) {
			return to_string(num) + "_delayed_write";
		}
		else {
			return to_string(num);
		}
	}
	bool operator==(const Block& data) {
		if (data.num == num) {
			return true;
		}
		return false;
	}
};

DoublyLinkedList<Block> freeList;
LinkedQueue<Block>* header;

void ChangeState(int num) {					//release와 get의 상태를 바꾸는 함수
	int idx = num % Header_num;

	bool result = false;
	Block temp;

	LinkedQueueIterator<Block> iter(header[idx]);				//입력받은 block의 번호에 맞는 queue로 접근

	temp = iter.Next();

	while (iter.NextNotNull()) {
		if (temp.num == num) {									//해당 queue가 있다면
			if (temp.free == true) {							//상태를 바꾼다
				temp.free = false;
				freeList.Delete(temp);							//get이기 때문에 freeList에서 삭제
			}
			else {
				temp.free = true;
				freeList.Add(temp);								//release이기 때문에 freeList에 추가
			}
			header[idx].Replace(temp);							
			result = true;
			break;
		}
		temp = iter.Next();
	}

	if (result == false) {
		cout << "Error: Invalid Buffer\n";
	}
}

void ChangeStateDelay(int num) {								//Delay 상태를 바꾸는 함수
	int idx = num % Header_num;

	bool result = false;
	Block temp;

	LinkedQueueIterator<Block> iter(header[idx]);

	temp = iter.Next();

	while (iter.NextNotNull()) {
		if (temp.num == num) {
			if (temp.delay == true) {
				temp.delay = false;
			}
			else {
				temp.delay = true;
			}
			freeList.Replace(temp);
			header[idx].Replace(temp);
			result = true;
			break;
		}
		temp = iter.Next();
	}

	if (result == false) {
		cout << "Error: Invalid Buffer\n";
	}
}

Block getblk(int num) {
	bool exist = false;			
	bool find = false;									

	int idx = num % Header_num;

	Block temp;
	int count = 0;
	int count2 = 0;
	while (!find) {
		LinkedQueueIterator<Block> iter(header[idx]);

		temp = iter.Next();

		while (iter.NextNotNull()) {						//해쉬 대기 행렬에 있는지 확인
			if (temp.num == num) {
				exist = true;
				break;
			}
			temp = iter.Next();
		}

		if (exist) {										//있다면
			if (temp.free == false) {						//이미 사용중이라면		/*경우 5*/
				count++;
				if (count == 3) {							//3초 기다리고
					ChangeState(num);						//release해줌
				}
				cout << "Waiting...\n";
				Sleep(1000);
				continue;
			}
			temp.free = false;								//해당 buffer의 상태를 get하고		/*경우 1*/
			freeList.Delete(temp);							//freeList에서 삭제후
			header[idx].Replace(temp);						//상태 update
			return temp;
		}
		else {												/*블록이 해쉬 대기행렬에 없다면*/
			if (freeList.GetLength() == 0) {				//자유 리스트가 비었으면		/*경우 4*/
				count2++;
				if (count2 == 3) {										//3초를 기다리고 하나를 release해줌
					header[(num % Header_num) / 2].Dequeue(temp);		
					temp.free = true;
					header[(num % Header_num) / 2].Replace(temp);
					freeList.Add(temp);
				}
				cout << "Waiting...\n";
				Sleep(1000);
				continue;
			}
			temp = freeList.pop_back();

			if (temp.delay == true) {								//delay되어있는 것이라면		/*경우 3*/
				freeList.Delete(temp);								//지우고 다음꺼
				continue;
			}

			header[temp.num % Header_num].Delete(temp);				//해쉬 대기행렬에서 삭제 후
			temp.num = num;
			temp.delay = false;
			temp.free = false;

			header[num % Header_num].Enqueue(temp);					//버퍼 삽입

			return temp;
		}
	}
}

int main() {

	/////////////////////////////////////입력 받는 부분/////////////////////////////////////////
	do
	{
		cout << "Enter the Size of Hash Queue Header(3~9): ";
		cin >> Header_num;
		if (Header_num < 3 && Header_num > 9) {
			cout << "Error: Out_of_Range!\n";
			continue;
		}
		break;
	} while (1);

	header = new LinkedQueue<Block>[Header_num];
	
	for (int i = 0; i < Header_num; i++) {
		do {
			cout << "Enter the Size of Block(3~9): ";
			cin >> Block_num;
			if (Block_num < 3 && Block_num > 9) {
				cout << "Error: Out_of_Range!\n";
				continue;
			}
			break;
		} while (1);
		cout << "Enter N block numbers: ";
		int num;
		for (int j = 0; j < Block_num; j++) {
			cin >> num;
			Block temp(num);
			header[i].Enqueue(temp);
		}
	}

	do
	{
		cout << "Enter the Size of FreeList: ";
		cin >> FreeList_num;
		if (FreeList_num < 3 && FreeList_num > 9) {
			cout << "Error: Out_of_Range!\n";
			continue;
		}
		break;
	} while (1);

	int num;
	cout << "Enter N block numbers: ";

	for (int i = 0; i < FreeList_num; i++)
	{	
		cin >> num;
		Block temp(num);
		temp.free = true;
		freeList.Add(temp);
		int idx = num % Header_num;
		header[idx].Replace(temp);
	}

	////////////////////////////////////////////////////////////////////////////////////////

	while (1) {
		int command;									/////////////////////출력 부분///////////////////////
		for (int i = 0; i < Header_num; i++) {
			cout << "blk no " << i << " mode " << Header_num << " [ ";
			LinkedQueueIterator<Block> iter(header[i]);
			Block temp;
			temp = iter.Next();
			while (iter.NextNotNull()) {
				cout << temp.Display() << " ";
				temp = iter.Next();
			}
			cout << " ]"<< endl;
		}
		cout << "free list [ ";
		Block temp;
		DoublyIterator<Block> iter(freeList);
		temp = iter.Next();
		while (iter.NextNotNull()) {
			cout << temp.Display() << " ";
			temp = iter.Next();
		}
		cout << " ]" << endl;
		cout << "1. change block status to delayed write\n";
		cout << "2. getblk\n";
		cout << "3. exit\nEnter the Command-> ";
		cin >> command;
		int n;
		if (command == 1 || command == 2) {
			cout << "Enter the number of block: ";
			cin >> n;
		}
														////////////////////////////////////////////////////

																	////////실행 부분//////////
		switch (command)
		{
		case 1:
			ChangeStateDelay(n);
			break; 

		case 2:
			cout << "Get Block: "<< getblk(n).num << "\n\n";
			break;

		case 3:
			return 0;
			break;

		default:
			cout << "Error: Illigal Command!\n";
			break;
		}
	}
																	//////////////////////////
	return 0;
}