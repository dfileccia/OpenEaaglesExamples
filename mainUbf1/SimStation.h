//------------------------------------------------------------------------------
// Class: SimStation
//
// Base class: Simulation::Station -> Ubf::AgentStation -> SimStation
//------------------------------------------------------------------------------

#ifndef __SimStation_H__
#define __SimStation_H__

#include "openeaagles/ubf/AgentStation.h"

namespace Eaagles {

namespace Basic { class Table1; class PairStream; }
namespace Glut { class GlutDisplay; }
namespace Simulation { class AirVehicle; }

namespace MainUbf1 {

//------------------------------------------------------------------------------
// Class: SimStation
//
// Description: Example station class that adds our graphics, which is managed by
//              a GlutDisplay, adds processing of the Hands On Throttle And Stick
//              (HOTAS) device, which is usually just a joystick, and adds stepping
//              of our ownship to the next local, air vehicle player.
//
// Form Name: SimStation
// Slots:
//      display       <BasicGL::GlutDisplay>  ! Main graphics display
//
//------------------------------------------------------------------------------

class SimStation : public Ubf::AgentStation
{
    DECLARE_SUBCLASS(SimStation, Ubf::AgentStation)

public:

    SimStation();

   // Step our "ownship" to the next local air vehicle
   void stepOwnshipPlayer();

   // Slot functions
   virtual bool setSlotMainDisplay(Glut::GlutDisplay* const d);

   // Basic::Component Interface
   virtual void updateTC(const LCreal dt = 0.0f);
   virtual void reset();

private:

    // Main Display
    SPtr<Glut::GlutDisplay> mainDisplay;
    bool displayInit;

};

}
}

#endif


