#pragma once

template <typename T>
class Past {
	T _value;
	T _previous = {}; // TODO: optional or something

public:
	explicit Past(const T& value) : _value(value) {}
	explicit Past(const T& value, const T& previous) : _value(value), _previous(previous) {}

	T previous() {
		return _previous;
	}

	Past& operator =(const T& right) {
		this->_previous = this->_value;
		this->_value = right;
		return *this;
	}

	T operator + (const T& right) {
		return this->_value + right;
	}
	T operator - (const T& right) {
		return this->_value - right;
	}
	T operator * (const T& right) {
		return this->_value * right;
	}
	T operator / (const T& right) {
		return this->_value / right;
	}

	T operator + (const Past& right) {
		return this->_value + right._value;
	}
	T operator - (const Past& right) {
		return this->_value - right._value;
	}
	T operator * (const Past& right) {
		return this->_value * right._value;
	}
	T operator / (const Past& right) {
		return this->_value / right._value;
	}

	const Past& operator -- (T) {
		this->_previous = this->_value;
		--this->_value;
		return *this;
	}
	const Past& operator ++ (T) {
		this->_previous = this->_value;
		++this->_value;
		return *this;
	}

	const Past& operator += (const T& right) {
		this->_previous = this->_value;
		this->_value += right;
		return *this;
	}
	const Past& operator -= (const T& right) {
		this->_previous = this->_value;
		this->_value -= right;
		return *this;
	}

	const Past& operator *= (const T& right) const {
		this->_previous = this->_value;
		this->_value *= right;
		return *this;
	}
	const Past& operator /= (const T& right) const {
		this->_previous = this->_value;
		this->_value /= right;
		return *this;
	}

	bool operator < (const T& right) const { return this->_value < right; }
	bool operator <= (const T& right) const { return this->_value <= right; }
	bool operator > (const T& right) const { return this->_value > right; }
	bool operator >= (const T& right) const { return this->_value >= right; }
	bool operator == (const T& right) const { return this->_value == right; }

	bool operator < (const Past& right) const { return this->_value < right._value; }
	bool operator <= (const Past& right) const { return this->_value <= right._value; }
	bool operator > (const Past& right) const { return this->_value > right._value; }
	bool operator >= (const Past& right) const { return this->_value >= right._value; }
	bool operator == (const Past& right) const { return this->_value == right._value; }

	operator T() const { return _value; }
};
