//
// Created by daddabarba on 24/02/19.
//

#ifndef REACT_NOTIFICATION_H
#define REACT_NOTIFICATION_H

#include "Defs.h"

REACT_CONC_START

class Observer {

public:

    virtual void has_changed() = 0;
};

class Observable {

public:
    auto link_successor(Observer* successor) -> void{
        _successors.push_back(successor);
    }

protected:

    std::vector<Observer*> _successors;

    virtual auto notify_change() -> void {
        for(Observer* successor : _successors)
            successor->has_changed();
    }

};

REACT_CONC_END


#endif //REACT_NOTIFICATION_H
