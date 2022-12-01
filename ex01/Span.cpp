#include "Span.hpp"

Span::Span() {
	_capacity = 0;
}

Span::Span(const Span &other) {
	*this = other;
}

Span::Span(unsigned int n) {
	_capacity = n;
	_arr = std::vector<int>(n);
}

Span::~Span() {}

Span &Span::operator=(const Span &rhs) {
	if (this == &rhs)
		return *this;

	_capacity = rhs._capacity;
	_arr = rhs._arr;
	return *this;
}

void Span::addNumber(int n) {
	if (_arr.size() == _capacity)
		throw SpanError("This throws a spanner in the works.. We're already at capacity!\n");

	_arr.push_back(n);
}

int Span::shortestSpan() const {
	std::lower_bound(_arr.begin(), _arr.end(),)
	return 0;
}

int Span::longestSpan() const
{
	return 0;
}


Span::SpanError::SpanError(const char *reason): _reason(reason) {}

const char *Span::SpanError::what() const throw() {
	return _reason;
}
