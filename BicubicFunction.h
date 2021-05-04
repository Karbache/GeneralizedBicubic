#ifndef OPENSIM_TESTBICUBIC_H_
#define OPENSIM_TESTBICUBIC_H_
/* -------------------------------------------------------------------------- *
 *                              OpenSim:  Paraboloid.h                        *
 * -------------------------------------------------------------------------- *
 * The OpenSim API is a toolkit for musculoskeletal modeling and simulation.  *
 * See http://opensim.stanford.edu and the NOTICE file for more information.  *
 * OpenSim is developed at Stanford University and supported by the US        *
 * National Institutes of Health (U54 GM072970, R24 HD065690) and by DARPA    *
 * through the Warrior Web program.                                           *
 *                                                                            *
 * Copyright (c) 2005-2017 Stanford University and the Authors                *
 * Author(s): Abdelkader Karbache                                             *
 *                                                                            *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may    *
 * not use this file except in compliance with the License. You may obtain a  *
 * copy of the License at http://www.apache.org/licenses/LICENSE-2.0.         *
 *                                                                            *
 * Unless required by applicable law or agreed to in writing, software        *
 * distributed under the License is distributed on an "AS IS" BASIS,          *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   *
 * See the License for the specific language governing permissions and        *
 * limitations under the License.                                             *
 * -------------------------------------------------------------------------- */


 // INCLUDES
#include <string>
#include <OpenSim/Common/Function.h>
#include <OpenSim/Common/FunctionAdapter.h>



using namespace OpenSim;
using namespace std;

namespace OpenSim {

	//=============================================================================
	//=============================================================================
	/**
	 * A class for representing a paraboloid function.
	 *
	 *
	 * @author Abdelkader Karbache
	 * @version 1.0
	 */
	class BicubicFunction : public Function {
		OpenSim_DECLARE_CONCRETE_OBJECT(BicubicFunction, Function);
	protected:
		//==============================================================================
		// PROPERTIES
		//==============================================================================
		//=============================================================================
		// METHODS
		//=============================================================================
	public:
		//Default construct, copy and assignment

		//Properties
		OpenSim_DECLARE_LIST_PROPERTY(x_gridpoints, double,
			"The gridpoints in the x direction"
		);
		OpenSim_DECLARE_LIST_PROPERTY(y_gridpoints, double,
			"The gridpoints in the y direction"
		);
		OpenSim_DECLARE_LIST_PROPERTY(function_points, double,
			"The evaluation of the gridpoints"
		);


		// Convenience Constructor
		BicubicFunction();




		virtual ~BicubicFunction();

		//--------------------------------------------------------------------------
		// EVALUATION
		//--------------------------------------------------------------------------

		SimTK::Function* createSimTKFunction() const override;

		int getArgumentSize() const override;
		int getMaxDerivativeOrder() const override;


	private:

		void constructProperties();

		std::shared_ptr<SimTK::BicubicSurface> _surface;
		//=============================================================================
	};  // END class Paraboloid
	//=============================================================================
	//=============================================================================

} // end of namespace OpenSim

#endif  // OPENSIM_TESTBICUBIC_H_

