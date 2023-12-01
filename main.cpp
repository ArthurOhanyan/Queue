#include <iostream>
#include "prototype.h"

int main ()
{
	Queue<int> obj;
	std::cout << " just created obj : capacity is : " << obj.cap() << std::endl;
	obj.enqueue(1);
	obj.enqueue(2);
	obj.enqueue(3);
	obj.enqueue(4);
	obj.enqueue(5);
	obj.enqueue(6);
	obj.enqueue(7);
	obj.enqueue(8);
	std::cout << "isEmpty() " << std::boolalpha << obj.isEmpty() << std::endl;
	std::cout << obj << std::endl;

	for (int i = 0; i < 5; ++i){
		
		 obj.dequeue();
	}
	std::cout << obj << std::endl;
	std::cout << std::endl;
	//std::cout << " after equeue (8) :: and dequeue (5) :: capacity is :  " << obj.cap() << std::endl;
	obj.enqueue(9);
	obj.enqueue(10);
	obj.enqueue(11);
	std::cout << obj << std::endl;
	std::cout << " after enqueue (3) :: capcsity is : " << obj.cap() << std::endl;
	std::cout << " size () is : " << obj.size() << std::endl;
	std::cout << " front() elem is : " << obj.front() << std::endl;
	std::cout << " rear () elem is : " << obj.rear() << std::endl;
	for (int i = 12; i < 50; ++i){
		
		obj.enqueue(i);
	}
	
	std::cout << " after enqueue (6) :: capacity is : " << obj.cap() << std::endl;
	std::cout << obj << std::endl;
	obj.dequeue();
	std::cout << " size = " << obj.size() << std::endl;

	std::cout << " fornt() elem is " << obj.front() << std::endl;
	std::cout << " rear () elem is " << obj.rear() << std::endl;
	std::cout << " isEmpty : " << std::boolalpha << obj.isEmpty() << std::endl;
	//int x = obj.size();
	//for (int i = 0; i < x; ++i){
		
	//	obj.dequeue();
	//}
	//std::cout << " size is = " << obj.size() << std::endl;
	//std::cout << " isEmpty : " << std::boolalpha << obj.isEmpty() << std::endl;
	Queue<int> obj1;
	obj1 = obj;
	std::cout << " print obj1 :: " << obj1 << std::endl;
	Queue<int> obj2(obj1);
	std::cout << " print obj2 :: " << obj2 << std::endl; 


}
