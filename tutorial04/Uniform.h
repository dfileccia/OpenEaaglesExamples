//------------------------------------------------------------------------------
// Class: Uniform
// Description: Generates Random Numbers
//------------------------------------------------------------------------------

#ifndef __Eaagles_Tutorial_Uniform_H__
#define __Eaagles_Tutorial_Uniform_H__

#include "Random.h"

namespace Eaagles {

namespace Basic   { class Number; }

namespace Tutorial {

class Uniform : public Random
{
   DECLARE_SUBCLASS(Uniform,Random)

public:

   Uniform(void);

   // data access functions
   void setMax(const int);
   void setMin(const int);

   // slot table functions
   bool setSlotMax(const Basic::Number* const);
   bool setSlotMin(const Basic::Number* const);

   // Random class interface
   virtual int getNum(void) const;

private:
   int max;
   int min;
};

} // namespace Tutorial
} // namespace Eaagles

#endif
