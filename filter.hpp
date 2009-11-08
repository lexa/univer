#define FILTER_TYPE double
#include <string>

#include <iostream>
#include <boost/numeric/ublas/blas.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/assign/std/vector.hpp> 
#include <boost/random.hpp>
#include <boost/assert.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/foreach.hpp>

#include <vector>
#define MU 0.03
//#define sigma 0.99f;//коэф забываний

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

	vector <FILTER_TYPE> G, Y;
	matrix <FILTER_TYPE> P;

	FILTER_TYPE alpha, e, gamma;
};
