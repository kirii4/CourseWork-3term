#pragma once
#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include <iostream>
#include <stack>
#include <memory>
#include <fstream>

template<typename T>
class Transaction
{
	std::stack<std::shared_ptr<T>> currState;

public:
	Transaction() {
		std::shared_ptr<T> ptr = std::make_shared<T>();
		this->currState.push(ptr);
	}
	Transaction(const Transaction& obj) {
		this->currState = obj.currState;
	}
	~Transaction()
	{
		while (!currState.empty()) {
			currState.pop();
		}
	}

	Transaction& operator=(const Transaction& obj);
	void show();
	bool beginTransaction(T);
	void commit();
	void deleteTransactions();
	void clear();
	std::shared_ptr<T> operator->();
};

template<typename T>
Transaction<T>& Transaction<T>::operator=(const Transaction& obj)
{
	if (this != &obj)
	{
		while (!currState.empty()) {
			currState.pop();
		}
		this->currState = obj.currState;
	}
	return *this;
}

template<typename T>
std::shared_ptr<T> Transaction<T>::operator->()
{
	return this->currState.top();
}

template<typename T>
void Transaction<T>::show()
{
	if (!currState.empty()) {
		std::stack<std::shared_ptr<T>> buffer = currState;
		while (!buffer.empty()) {
			buffer.top().show();
			buffer.pop();
		}
	}
}

template<typename T>
bool Transaction<T>::beginTransaction(T newData)
{
	std::shared_ptr<T> ptr = std::make_shared<T>(currState.top());
	currState.push(ptr);
	if (!currState.top()) return false;
	currState.top().add(newData);
	return true;	
}

template<typename T>
void Transaction<T>::commit()
{
	std::shared_ptr<T> val = currState.top();
	while (!currState.empty()) {
		currState.pop();
	}
	currState.push(val);
}

template<typename T>
void Transaction<T>::clear()
{
	currState.pop();
}

template<typename T>
void Transaction<T>::deleteTransactions()
{
	if (!this->currState.empty)
	{
		currState.pop();
	}
}
#endif //TRANSACTIONS_H