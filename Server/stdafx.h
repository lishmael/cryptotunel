// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__8659C803_7480_4B3F_B803_CDCBC8CFBAD7__INCLUDED_)
#define AFX_STDAFX_H__8659C803_7480_4B3F_B803_CDCBC8CFBAD7__INCLUDED_

#if defined(_MSC_VER)
# pragma once
# pragma warning(disable:4267)
# pragma warning(disable:4661)
#endif

#include "debugmode.h"

#define KB 0

// Runtime Includes
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
using std::string;

#include <stdexcept>
using std::exception;
using std::runtime_error;

#endif // !defined(AFX_STDAFX_H__8659C803_7480_4B3F_B803_CDCBC8CFBAD7__INCLUDED_)
