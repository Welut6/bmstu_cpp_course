#pragma once

#include <exception>
#include <iostream>
#include <utility>

namespace bmstu
{
template <typename T>
class stack
{
   public:
	stack() : data_(nullptr), size_(0),capacity_(0) {}
	~stack() {
		clear();
		delete[] reinterpret_cast<char*>(data_);
	}
	bool empty() const noexcept {
		return size_ == 0;
	}
	size_t size() const noexcept {
		return size_;
	}

	template <typename... Args>
	void emplace(Args&&... args)
	{
		if(size_==capacity_){
			reserve(size_ +1);
		}
		new(data_+size_) T(std::forward<Args>(args)...);
		++size_;
	}

	void push(T&& value) {
		if (size_ == capacity_){
			reserve(size_+1);
		}
		new (data_+size_) T(std::move(value));
		++size_;
	}

	void clear() noexcept {
		while (size_ > 0){
			--size_;
			data_[size_].~T();
		}
	}

	void push(const T& value) {
		if (size_ == capacity_){
			reserve(size_+1);
		}
		new (data_+size_) T(value);
		++size_;
	}

	void pop() {
		if(empty()){
			throw std::underflow_error("stack empty");
		}
		--size_;
		data_[size_].~T();
	}

	T& top() {
		if(empty()){
			throw std::underflow_error("stack empty");
		}
		return data_[size_-1]; 
	}

	const T& top() const { return data_[size_-1]; }

   private:
   	void reserve(size_t new_capacity){
		if (new_capacity <= capacity_){
			return;
		}
		T* new_data = reinterpret_cast<T*>(new char[new_capacity*sizeof(T)]);
		for(size_t i=0;i<size_;++i){
			new (new_data+i) T(std::move(data_[i]));
			data_[i].~T();
		}
		delete[] reinterpret_cast<char*>(data_);
		data_ = new_data;
		capacity_= new_capacity;
	}

	T* data_;
	size_t size_;
	size_t capacity_;
};
}  // namespace bmstu 
