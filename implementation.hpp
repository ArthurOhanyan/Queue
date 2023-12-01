#include <iostream>

template <typename T>
std::ostream& operator << (std::ostream& os, Queue<T>& q)
{
	return q.operator<<(os);
}

template <typename T>
Queue<T>::Queue ()
{
	m_ptr = nullptr;
	m_size = 0;
	m_capacity = 0;
	m_r_index = 0;
	m_f_index = 0;
}

template <typename T>
Queue<T>::~Queue ()
{
	if (m_ptr){
		
		delete [] m_ptr;
		//m_ptr = nullptr;
	}

	m_size = 0;
	m_capacity = 0;
	m_r_index = 0;
	m_f_index = 0;
}

template <typename T>
Queue<T>::Queue (const Queue& obj)
{
	m_size = obj.m_size;
	m_capacity = obj.m_capacity;
	m_f_index = obj.m_f_index;
	m_r_index = obj.m_r_index;

	m_ptr = new T [m_capacity];
	for (int i = m_f_index; i > m_r_index; --i){
		
		m_ptr[i] = obj.m_ptr[i];
	}
	
}

template <typename T>
void Queue<T>::enqueue (const T& val)
{
	if (m_capacity == 0 || m_size == m_capacity || m_f_index <= (m_capacity / 2)){
		
		Queue::reallocator();
	}
	
	m_ptr [m_r_index--] = val;
	++m_size;
}

template <typename T>
T Queue<T>::dequeue ()
{
	if (!m_ptr){
	
		std::cout << " dequeue() :: nullptr error " << std::endl;
	        exit(1);	

	} else if (m_size == 0){
		
		std::cout << " The conteiner is empaty " << std::endl;
		exit (0);
	}

	--m_f_index;
	--m_size;
	return m_ptr [m_f_index + 1];

}

template <typename T>
T Queue<T>::front()
{
	if (!m_ptr){
	
		std::cout << " front () :: nullptr :: error " << std::endl;
		exit(1);

	} else if (m_size == 0){
		
		std::cout << " The conteiner is empty " << std::endl;
		exit(0);
	} 
		
	return m_ptr [m_f_index];

}

template <typename T>
T Queue<T>::rear ()
{
	if (!m_ptr){
	
		std::cout << " rear () :: nullptr :: error " << std::endl;
		exit(1);

	} else if (m_size == 0){
		
		std::cout << " The conteiner is empty " << std::endl;
		exit(0);
	} 

	return m_ptr [m_r_index + 1];
}

template <typename T>
bool Queue<T>::isEmpty ()
{
	if (m_size > 0){
		
		return false;
	}

	return true;
}

template <typename T>
int Queue<T>::size ()
{
	return m_size;
}

template <typename T>
int Queue<T>::cap ()
{
	return m_capacity;
}
