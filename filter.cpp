#include "filter.hpp"

using namespace boost::numeric::ublas;


Filter::Filter(size_t _len)
	:len(_len), 
	 W(len, 0),
	 X(len, 0)
{
}

Filter::~Filter()
{
}

FILTER_TYPE
Filter::result() const
{
	FILTER_TYPE sum=0;
	for (size_t i=0; i < len; ++i)
	{
		sum += W[i]*X[i];
	}
	return sum;
}

//сдвиг вправо
template <class elem_type>
vector <elem_type>
push_in_vector(vector <elem_type> &v, elem_type x)
{
	// std::cerr << v[0] << std::endl;
	for(size_t i = v.size()-1; i > 0; --i)
	{
//		std::cerr << i <<  " " << v[i-1] << std::endl;
		v[i] = v[i-1];
	}
	v[0]=x;
	return v;
}

FILTER_TYPE
Filter::next(FILTER_TYPE x, FILTER_TYPE ideal)
{
	push_in_vector(X, x);
	FILTER_TYPE rez = result();
	FILTER_TYPE eps = ideal - rez;
	W += 2*MU*eps*X;
//	W = solve(prod(trans (X), X), prod(X, Y));
	return eps;
}
