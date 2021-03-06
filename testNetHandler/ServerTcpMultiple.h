//------------------------------------------------------------------------------
// Class: ServerTcpMultiple
//------------------------------------------------------------------------------
#ifndef __Eaagles_Test_ServerTcpMultiple_H__
#define __Eaagles_Test_ServerTcpMultiple_H__

#include "Endpoint.h"

namespace Eaagles {
namespace Test {

//------------------------------------------------------------------------------
// Class:  ServerTcpMultiple
//
// Description:
//
// Factory name: ServerTcpMulti
//
//------------------------------------------------------------------------------
class ServerTcpMultiple : public Endpoint
{
   DECLARE_SUBCLASS(ServerTcpMultiple, Endpoint)

public:
   ServerTcpMultiple();

   // Component interface
   virtual void updateData(const LCreal dt = 0.0f);
   virtual void reset();

};

}
}

#endif
