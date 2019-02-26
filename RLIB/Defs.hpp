//
// Created by daddabarba on 25/02/19.
//

#ifndef RLIB_DEFS_H
#define RLIB_DEFS_H

#pragma once

#define RLIB_NS rlib
#define RLIB_INTERFACES_NS rlib_interfaces
#define RLIB_ABSTRACT_NS rlib_abstract

#define RLIB_START namespace RLIB_NS {
#define RLIB_END }
#define RLIB ::RLIB_NS

#define RLIB_INTERFACES_START RLIB_START namespace RLIB_INTERFACES_NS {
#define RLIB_INTERFACES_END } RLIB_END
#define RLIB_INTERFACES RLIB::RLIB_INTERFACES_NS

#define RLIB_ABSTRACT_START RLIB_START namespace RLIB_ABSTRACT_NS {
#define RLIB_ABSTRACT_END } RLIB_END
#define RLIB_ABSTRACT RLIB::RLIB_ABSTRACT_NS

typedef unsigned int Action;
typedef unsigned int State;

typedef unsigned int Space_Size;

#endif //RLIB_DEFS_H