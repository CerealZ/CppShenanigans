#pragma once
#include <functional>
#include <iostream>

template <typename  T>
class Signal {
	using on_change = std::function<void(Signal&)>;
	T _value;
	on_change _on_change;

public:
	explicit Signal(const on_change& callback) : _on_change(callback) { }
	Signal(T value, on_change callback) : _value(value), _on_change(std::move(callback)) { }

	/*explicit Signal(const on_change callback) : _on_change(callback) { }
	Signal(T value, const on_change callback) : _on_change(callback), _value(value) { }*/

	Signal& emit() {
		this->_on_change(*this);
		return *this;
	}

	const Signal& operator -- (T) {
		--this->_value;
		return this->emit();
	}
	const Signal& operator ++ (T) {
		++this->_value;
		return this->emit();
	}

	const Signal& operator += (const T& right) {
		this->_value += right;
		return this->emit();
	}
	const Signal& operator -= (const T& right) {
		this->_value -= right;
		return this->emit();
	}

	const Signal& operator *= (const T& right) const {
		this->_value *= right;
		return this->emit();
	}
	const Signal& operator /= (const T& right) const {
		this->_value /= right;
		return this->emit();
	}

	bool operator < (const T& right) const { return this->_value < right; }
	bool operator <= (const T& right) const { return this->_value <= right; }
	bool operator > (const T& right) const { return this->_value > right; }
	bool operator >= (const T& right) const { return this->_value >= right; }
	bool operator == (const T& right) const { return this->_value == right; }

	bool operator < (const Signal& right) const { return this->_value < right._value; }
	bool operator <= (const Signal& right) const { return this->_value <= right._value; }
	bool operator > (const Signal& right) const { return this->_value > right._value; }
	bool operator >= (const Signal& right) const { return this->_value >= right._value; }
	bool operator == (const Signal& right) const { return this->_value == right._value; }

	friend std::ostream& operator << (std::ostream& os, const Signal& self) {
		os << self._value;
		return os;
	}

	operator T() const { return _value; }
};
