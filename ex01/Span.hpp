#pragma once

#include <exception>
#include <vector>

class Span {
	private:
		unsigned int _capacity;
		std::vector<int> _arr;

	public:
		Span();
		Span(const Span &other);
		explicit Span(unsigned int n);
		virtual ~Span();
		Span &operator=(const Span &rhs);

		void addNumber(int n);
		template<typename T>
		void addRange(T &begin, T &end);

		int shortestSpan() const;
		int longestSpan() const;

		class SpanError: public std::exception {
			private:
				const char *_reason;
			public:
				explicit SpanError(const char *reason);
				const char *what() const throw();
		};
};

template<typename T>
void Span::addRange(T &begin, T &end) {
	const unsigned int count = std::distance(begin, end);
	if (count > _capacity - _arr.size())
		throw SpanError("Adding this many values would overflow!");
	_arr.insert(_arr.end(), begin, end);
}