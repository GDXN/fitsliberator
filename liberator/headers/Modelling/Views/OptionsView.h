// The ESA/ESO/NASA FITS Liberator - http://code.google.com/p/fitsliberator
//
// Copyright (c) 2004-2010, ESA/ESO/NASA.
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the names of the European Space Agency (ESA), the European 
//       Southern Observatory (ESO) and the National Aeronautics and Space 
//       Administration (NASA) nor the names of its contributors may be used to
//       endorse or promote products derived from this software without specific
//       prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
// ARE DISCLAIMED. IN NO EVENT SHALL ESA/ESO/NASA BE LIABLE FOR ANY DIRECT, 
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// =============================================================================
//
// The ESA/ESO/NASA FITS Liberator uses NASA's CFITSIO library, libtiff, 
// TinyXML, Boost C++ Libraries, Object Access Library and Intel Threading 
// Building Blocks.
//
// =============================================================================
//
// Project Executive:
//   Lars Lindberg Christensen
//
// Technical Project Manager:
//   Lars Holm Nielsen
//
// Developers:
//   Kaspar Kirstein Nielsen & Teis Johansen
// 
// Technical, scientific support and testing: 
//   Robert Hurt
//   Davide De Martin
//
// =============================================================================

/** @file       Declares the OptionsModel class.
    $Log: OptionsView.h,v $
    Revision 1.5  2010/09/25 15:32:49  kaspar
    *** empty log message ***

    Revision 1.4  2010/09/14 13:01:53  kaspar
    *** empty log message ***

    Revision 1.3  2008/09/23 15:01:07  kaspar
    *** empty log message ***

    Revision 1.2  2008/09/19 15:19:54  lars
    Implmented the Mac Preference UI

    Revision 1.1  2008/09/15 08:09:07  teis
    Implemented the Options dialog

    @version	$Revision: 1.5 $
    @date		$Date: 2010/09/25 15:32:49 $
    @author		Teis Johansen <teis@siet.dk>
    @author		Kaspar Kirstein Nielsen <kaspar@barmave.dk>
    @author		Lars Holm Nielsen <lars@hankat.dk>  */

#pragma once

#include "FitsLiberator.h"
#include "Observer.h"
#include "OptionsModel.h"
#include "OptionsController.h"

namespace FitsLiberator {
	namespace Modelling {
        /** View for the Options dialog. */
		class OptionsView : public Observer {
            typedef Observer super;
        protected:
            const OptionsModel& model;       ///< Associated model
            OptionsController&  controller;  ///< Associated controller
            bool                revert;      ///< Revert the state at destruction

            virtual void Update(Models* models);
            virtual void Update() = 0;

            void OnGuessSelected(int index);
            void OnStretchSelected(int index);
            void OnBlackLevelPercentageChanged(double value);
            void OnWhiteLevelPercentageChanged(double value);
            void OnScaledPeakChanged(double value);
			Int getStretchFunctionIndex() const;		
        public:
            /** Constructor.
                @param model Associated model.
                @param controller Associated controller. */
            OptionsView(const OptionsModel& model, OptionsController& controller);
            virtual ~OptionsView();
		};
	}
}