#ifndef VORTEX_HH
#define VORTEX_HH

#include "actor.hh"

#include <string>

namespace Common{

class Vortex : public Actor
{
public:
    /**
    * @brief Constructor, sets the id of the vortex.
    * @param typeId the id of the vortex.
    */
    Vortex(int typeId);
    /**
     * @copydoc Common::Actor::doAction()
     */
    virtual void doAction();

    /**
     * @copydoc Common::Actor::getActorType()
     */
    virtual std::string getActorType() const;
};
}
#endif // VORTEX_HH
