// -------------------------------------------------------------------------------
// Class: MapPage
//
// Description:
//      Derived MapPage that will show how to add, remove, and update symbols with the
//      SymbolLoader class.
// -------------------------------------------------------------------------------
#ifndef __Eaagles_Example_MapPage_H__
#define __Eaagles_Example_MapPage_H__

#include "openeaagles/basicGL/MapPage.h"

namespace Eaagles {
namespace Simulation { 
    class Player; 
}
namespace BasicGL {
    class SymbolLoader;
}
namespace Example {

class Station;

class MapPage : public BasicGL::MapPage
{
    DECLARE_SUBCLASS(MapPage, BasicGL::MapPage)
    
public:
    MapPage();

    // BasicGL::Graphic interface
    virtual void drawFunc();

    // Basic::Component interface
    virtual void updateData(const LCreal dt = 0.000000);

private:
    // holds our players
    static const int MAX_PLAYERS = 200;
    static const int MAX_READOUTS = 20;
    Simulation::Player* player[MAX_PLAYERS];    // player pointer
    int playerIdx[MAX_PLAYERS];                 // index of our symbol for the given player
    BasicGL::SymbolLoader* loader;              // holds our loader for quick reference
    Station* stn;                   // holds our station (to get the player list quickly)
    // show where our lat/lons are
    SendData latsSD[MAX_READOUTS];
    int lats[MAX_READOUTS];
    SendData latReadoutXPosSD[MAX_READOUTS];
    float latReadoutXPos[MAX_READOUTS];
    SendData latReadoutYPosSD[MAX_READOUTS];
    float latReadoutYPos[MAX_READOUTS];
    // lons
    SendData lonsSD[MAX_READOUTS];
    int lons[MAX_READOUTS];
    SendData lonReadoutXPosSD[MAX_READOUTS];
    float lonReadoutXPos[MAX_READOUTS];
    SendData lonReadoutYPosSD[MAX_READOUTS];
    float lonReadoutYPos[MAX_READOUTS];
};

}  // end of Example namespace
}  // end of Eaagles namespace

#endif

