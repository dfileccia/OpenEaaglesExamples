//------------------------------------------------------------------------------
// Class: Factory
//------------------------------------------------------------------------------
#include "Factory.h"

#include "openeaagles/basic/Object.h"

#include "TestDisplay.h"
#include "TestIoHandler.h"
#include "SimStation.h"

// class factories
#include "xBehaviors/Factory.h"
#include "xPanel/Factory.h"

#include "openeaagles/basic/Factory.h"
#include "openeaagles/basicGL/Factory.h"
#include "openeaagles/gui/glut/Factory.h"
#include "openeaagles/dis/Factory.h"
#include "openeaagles/instruments/Factory.h"
#include "openeaagles/ioDevice/Factory.h"
#include "openeaagles/otw/Factory.h"
#include "openeaagles/sensors/Factory.h"
#include "openeaagles/simulation/Factory.h"
#include "openeaagles/dynamics/Factory.h"

#include <cstring>

namespace Eaagles {
namespace Example {

Factory::Factory()
{}

Basic::Object* Factory::createObj(const char* name)
{
    Basic::Object* obj = 0;

    if ( std::strcmp(name, SimStation::getFactoryName()) == 0 ) {
        obj = new SimStation();
    }
    else if ( std::strcmp(name, TestDisplay::getFactoryName()) == 0 ) {
        obj = new TestDisplay();
    }
    else if ( std::strcmp(name, TestIoHandler::getFactoryName()) == 0 ) {
        obj = new TestIoHandler();
    }

    // Example library packages
    if (obj == 0) obj = xBehaviors::Factory::createObj(name);
    if (obj == 0) obj = xPanel::Factory::createObj(name);

    // OpenEaagles packages
    if (obj == 0) obj = Simulation::Factory::createObj(name);
    if (obj == 0) obj = Instruments::Factory::createObj(name);
    if (obj == 0) obj = IoDevice::Factory::createObj(name);
    if (obj == 0) obj = Instruments::Factory::createObj(name);
    if (obj == 0) obj = Dynamics::Factory::createObj(name);
    if (obj == 0) obj = Sensor::Factory::createObj(name);
    if (obj == 0) obj = Otw::Factory::createObj(name);
    if (obj == 0) obj = Network::Dis::Factory::createObj(name);
    if (obj == 0) obj = BasicGL::Factory::createObj(name);
    if (obj == 0) obj = Glut::Factory::createObj(name);
    if (obj == 0) obj = Basic::Factory::createObj(name);

    return obj;
}

}  // end namespace Example
}  // end namespace Eaagles
