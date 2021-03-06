/*******************************************************************************

 File:    BfActStrategy.h
 Project: OpenSonATA
 Authors: The OpenSonATA code is the result of many programmers
          over many years

 Copyright 2011 The SETI Institute

 OpenSonATA is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 OpenSonATA is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with OpenSonATA.  If not, see<http://www.gnu.org/licenses/>.
 
 Implementers of this code are requested to include the caption
 "Licensed through SETI" with a link to setiQuest.org.
 
 For alternate licensing arrangements, please contact
 The SETI Institute at www.seti.org or setiquest.org. 

*******************************************************************************/

/*
Base class for beamformer activity strategies
 */

#ifndef BfActStrategy_H
#define BfActStrategy_H

#include "ActivityStrategy.h"

class BfActStrategy : public ActivityStrategy
{
 public:
   BfActStrategy(Scheduler *scheduler,
                 Site *site,
                 const NssParameters &nssParameters,
                 const string &actType,
                 int verboseLevel);

   virtual ~BfActStrategy();
   
 protected:
   // base class overrides
   virtual Activity *getNextActivity(NssComponentTree *nssComponentTree);
   virtual bool moreActivitiesToRun();
   virtual bool okToStartNewActivity();
   virtual void activityCompleteInternalHook(Activity *activity, bool failed);

   // subclass overrides
   virtual Activity * createNewActivity(NssComponentTree *nssComponentTree) = 0;

   // base class util functions (not to be overridden)
   NssParameters & getNssParameters();

 private:

   string actType_;
   NssParameters nssParameters_;
   bool tryAgain_;

   // Disable copy construction & assignment.
   // Don't define these.
   BfActStrategy(const BfActStrategy& rhs);
   BfActStrategy& operator=(const BfActStrategy& rhs);

};

#endif // BfActStrategy_H