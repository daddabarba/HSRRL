//
// Created by daddabarba on 2/1/19.
//

#ifndef REACT_DEFS_H
#define REACT_DEFS_H

#pragma once

#define REACT_NS reactcpp
#define REACT_CONC_NS reactconcrete
#define UTIL_NS utils
#define SEQ_NS sequences

#define REACT_START namespace REACT_NS {
#define REACT_END }
#define REACT ::REACT_NS

#define REACT_CONC_START REACT_START namespace REACT_CONC_NS {
#define REACT_CONC_END REACT_END }
#define REACT_CONC REACT::REACT_CONC_NS

#define UTIL_START namespace UTIL_NS {
#define UTIL_END }
#define UTIL ::UTIL_NS

#define SEQ_START UTIL_START namespace SEQ_NS {
#define SEQ_END UTIL_END }
#define SEQ UTIL::SEQ_NS

#endif //REACT_DEFS_H
