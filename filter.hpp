#define FILTER_TYPE float

#include <iostream>
#include <boost/numeric/ublas/blas.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/foreach.hpp>

#include <vector>
#define MU 0.01

using namespace boost::numeric::ublas ;

class Filter {
public:
	Filter(size_t _len);
	~Filter();
	FILTER_TYPE next(FILTER_TYPE x, FILTER_TYPE ideal);
	FILTER_TYPE result () const;
private:
	Filter(Filter&);
	Filter& operator=(Filter&);

	size_t len;
	vector <FILTER_TYPE> W, X;
};
