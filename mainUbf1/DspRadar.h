//------------------------------------------------------------------------------
// Class: DspRadar
//------------------------------------------------------------------------------
#ifndef __DspRadar_H_76638785_7DDB_4980_90B0_CB4418D57B3F__
#define __DspRadar_H_76638785_7DDB_4980_90B0_CB4418D57B3F__

#include "openeaagles/basicGL/Graphic.h"

namespace Eaagles {
   namespace Basic      { class PairStream; }
   namespace Simulation { class Radar; }

namespace MainUbf1 {

//------------------------------------------------------------------------------
// Class: DspRadar
// Description: Simple Realbeam B-Scan RADAR.  Displays the real-beam signal,
//              with color coded doppler shift, and overlayed with trackes.
// Form Name: DspRadar
//------------------------------------------------------------------------------
class DspRadar : public BasicGL::Graphic
{
   DECLARE_SUBCLASS(DspRadar,BasicGL::Graphic)

public:
   DspRadar();

   const Simulation::Radar* getRadar()         { return radar; }
   const Simulation::Radar* getRadar() const   { return radar; }
   bool setRadar(Simulation::Radar* const s)   { radar = s; return true; }

   // BasicGL::Graphic class functions
   virtual void drawFunc();

   // Basic::Component class functions 
   virtual void updateData(const LCreal dt = 0.0);

private:
    const Simulation::Radar* radar;     // The test RADAR sensor
    SendData    azSD;
    SendData    elSD;

    // Tracks
    enum { MAX_TRKS = 50 };
    unsigned int nTracks;                   // Number of tracks
    int ntsTrk;                             // Index of the 'next-to-shoot' track
    LCreal      trkRng[MAX_TRKS];           // Track's range                    (meters)
    LCreal      trkAz[MAX_TRKS];            // Track's relative azimuth
    LCreal      trkVel[MAX_TRKS];           // Track's velocity                 (m/s)
    LCreal      trkRelGndTrk[MAX_TRKS];     // Track's relative ground track (to nearest 45 deg)
};

} // End MainUbf1 namespace
} // End Eaagles namespace

#endif // __DspRadar_H__
