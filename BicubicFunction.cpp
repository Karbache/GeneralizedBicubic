#include "BicubicFunction.h"
#include <string>
#include "SimTKmath.h"
#include <OpenSim/Common/Function.h>
#include <OpenSim/Common/FunctionAdapter.h>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace OpenSim;
using namespace std;

//=============================================================================
// DESTRUCTOR AND CONSTRUCTORS
//============================================================================



// Convenience Constructor
BicubicFunction::BicubicFunction()
{
	// Construct Properties
	constructProperties();

}





//Deconstructor
BicubicFunction::~BicubicFunction() {
};





SimTK::Function* BicubicFunction::createSimTKFunction() const {
	// Set lengths for the vectors and matrix
	const int lengthx = getProperty_x_gridpoints().size();
	const int lengthy = getProperty_y_gridpoints().size();
	const int lengthf = getProperty_function_points().size(); //const
	// Set x and y vector for the bicubic spline
	SimTK::Vector x(lengthx);
	for (int i = 0; i < lengthx; ++i) {
		x[i] = get_x_gridpoints(i);
	}
	SimTK::Vector y(lengthy);
	for (int i = 0; i < lengthy; ++i) {
		y[i] = get_y_gridpoints(i);
	}
	// Get length surface points in property list and check it is compatible
	SimTK_ASSERT(lengthf == lengthx * lengthy, "{x,y,f} lengths are not corresponding");
	// Set the matrix of function evaluations for the bicubic spline
	SimTK::Matrix f(lengthx, lengthy);
	for (int i = 0; i < lengthx; ++i) {
		for (int j = 0; j < lengthy; ++j) {
			f[i, j] = get_function_points(i*lengthx + j);
		}
	}
	// Create a Bicubic Spline using the vectors and matrix
	_surface.reset(new SimTK::BicubicSurface(x, y, f, 1));
	

	return new SimTK::BicubicFunction(*_surface);
}
//Construct Properties
void BicubicFunction::constructProperties()
{
	setAuthors("Abdelkader Karbache");
	constructProperty_x_gridpoints();
	constructProperty_y_gridpoints();
	constructProperty_function_points();
}


int BicubicFunction::getArgumentSize() const { return 2; }
int BicubicFunction::getMaxDerivativeOrder() const { return 2; }
