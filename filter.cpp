#include "filter.hpp"

using namespace boost::numeric::ublas;

// #include <typeinfo> //for debug
#define w0 1
#define p0 0.05

Filter::Filter(size_t _len)
	:len(_len), 
	 W(len, w0),
	 X(len, 0),
	 G(len, 0),
	 Y(len, 0),
	 P(len, len, 0),
	 alpha(0),
	 e(0),
	 gamma(0.99)
{
	for(size_t i = 0; i < len; ++i)
	{
		P(i, i) = p0;
	}
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

template <class t>
void
print_vector (vector <t> v, std::string name = "")
{
	std::cout << name;
	BOOST_FOREACH(FILTER_TYPE o, v)
	{
		std::cout << o << " ";
	}
	std::cout << std::endl;
}

// vector <FILTER_TYPE>
// uduflt(vector <FILTER_TYPE> W, vector <FILTER_TYPE> X, matrix <FILTER_TYPE> U, FILTER_TYPE eps, FILTER_TYPE gamma, size_t len)
// {
	
// }



FILTER_TYPE
Filter::next(FILTER_TYPE x, FILTER_TYPE ideal)
{
	push_in_vector(X, x);
	FILTER_TYPE rez = result();
	FILTER_TYPE eps = ideal - rez;
//	W += 2*MU*eps*X;
   // G = P*X/(gamma + X'*P*X);	
   // P = (P - G*X'*P)/gamma;
   // 	W = W + G*E(i);	

//	W = uduflt(W,X,U,eps,gamma,len);
	G = prod(P,X)/(gamma + inner_prod(prod(X, P), X));
	P = (P - prod(outer_prod(G, X), P))/gamma;
	W = W + G*eps;
	return eps;
}
