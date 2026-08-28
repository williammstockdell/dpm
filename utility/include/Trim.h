/* ================================================================ */
/*                                                                  */
/* Licensed Materials - Property of Will Stockdell                  */
/*                                                                  */
/* DPM -- Distributed Process Manager                               */
/*                                                                  */
/* (C) Copyright Will Stockdell 2026                                */
/*                                                                  */
/* This software is available to you under the                      */
/* Eclipse Public License (EPL) version 1.0                         */
/*                                                                  */
/* ================================================================ */

#include <algorithm>
#include <cctype>
#include <string>

inline void trim_left(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isspace(c); }));
}

inline void trim_right(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !std::isspace(c); }).base(), s.end());
}

inline void trim(std::string& s) {
    trim_right(s);
    trim_left(s);
}
