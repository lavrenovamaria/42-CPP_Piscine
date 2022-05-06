template<typename T>
Array<T>::Array(unsigned int n): _len(n), _array(new T[_len]()){
	this->_array = new T[n]();
}