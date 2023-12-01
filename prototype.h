#include <iostream>

template <typename T>
class Queue 
{
	T* m_ptr;
	int m_size;
	int m_capacity;
	int m_r_index; // rear index
	int m_f_index; // front index

	void reallocator ()
	{		
		if (m_capacity == 0){
			
			m_capacity = 10;
			m_ptr = new T [m_capacity];
			m_r_index = m_capacity - 1;
			m_f_index = m_capacity - 1;
			
		
		} else {
		
			if (m_size == m_capacity){
			
				m_capacity *= 2;
				T* tmp = new T [m_capacity];
				std::cout << " m_size = " << m_size << std::endl;
				for (int i = 0; i < m_size; ++i){
					
					tmp [m_capacity - 1 - i] = m_ptr [m_size - 1 - i];
				}
				delete [] m_ptr;
				m_ptr = tmp;
				tmp = nullptr;
				m_f_index = m_capacity - 1;
				m_r_index = (m_capacity / 2) - 1;
				std::cout << " works reallocator : m_size == m_capacity " << std::endl;

			} else {
			
				for (int i = 0; i < m_size; ++i){
				
					m_ptr [m_capacity - 1 - i] = m_ptr [m_f_index - i];
				}

				m_f_index = m_capacity - 1;
				m_r_index = (m_capacity - m_size) - 1;
				std::cout << " works reallocator : replace the  elements " << std::endl;

			}
		} 	
	}
	public:

	Queue ();
	Queue (const Queue&);
	Queue (Queue&&);
	~Queue ();
	
	void enqueue (const T&);
	T dequeue ();
	T front ();
	T rear ();
	bool isEmpty ();
	int size ();
	int cap ();	

	std::ostream& operator << (std::ostream& os)
	{
		for (int i = 0; i < m_size; ++i){
			
			os << m_ptr [m_f_index - i] << " ";
		}

		return os;
	}

	Queue& operator=(const Queue& other)
	{
		if (this != &other){
			
			if (m_ptr){
				
				delete [] m_ptr;
			}

			m_size = other.m_size;
			m_capacity = other.m_capacity;
			m_f_index = other.m_f_index;
			m_r_index = other.m_r_index;
			m_ptr = new T [m_capacity];
			for (int i = m_f_index; i > m_r_index; --i){
				
				m_ptr [i] = other.m_ptr[i];
			}

		}

		return *this;
	}

};


#include "implementation.hpp"
