//
// Created by daddabarba on 25/02/19.
//

#ifndef RLIB_DEFS_H
#define RLIB_DEFS_H

#pragma once

#define RLIB_NS rlib
#define RLIB_INTERFACES_NS rlib_interfaces

#define RLIB_START namespace RLIB_NS {
#define RLIB_END }
#define RLIB ::RLIB_NS

#define RLIB_INTERFACES_START RLIB_START namespace RLIB_INTERFACES_NS {
#define RLIB_INTERFACES_END } RLIB_END
#define RLIB_INTERFACES RLIB::RLIB_INTERFACES_NS

typedef unsigned int Action;
typedef unsigned int State;

#endif //RLIB_DEFS_H