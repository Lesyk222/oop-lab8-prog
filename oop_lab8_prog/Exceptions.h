#pragma once
#include <iostream>
using namespace std;
class CExceptions : public exception
{
 private:
	 const char* errorMsg;
 public:
	 CExceptions();
	 CExceptions(const char* msg);
	 const char* what() const noexcept override;
	 virtual ~CExceptions() = 0;
};

class CBadAlloc : public CExceptions
{
 public:
	 CBadAlloc();
	 CBadAlloc(const char* msg);
};

class CBadMaxMin : public CExceptions
{
 public:
	CBadMaxMin();
	CBadMaxMin(const char* msg);
};

class CBadDelete : public CExceptions
{
 public:
	CBadDelete();
	CBadDelete(const char* msg);
};

class CBadInput : public CExceptions
{
 public:
	 CBadInput();
	 CBadInput(const char* msg);
};