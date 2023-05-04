#include "Exceptions.h"

CExceptions::CExceptions() {
	errorMsg = "Error.";
}

CExceptions::CExceptions(const char* msg) {
	errorMsg = msg;
}

const char* CExceptions::what() const noexcept{
	return errorMsg;
}
CExceptions::~CExceptions() {}

CBadAlloc::CBadAlloc() : CExceptions("Error with allocating memory!") {}
CBadAlloc::CBadAlloc(const char* msg) : CExceptions(msg) {}

CBadMaxMin::CBadMaxMin() : CExceptions("Error! Multiset is empty!") {}
CBadMaxMin::CBadMaxMin(const char* msg) : CExceptions(msg) {}

CBadDelete::CBadDelete() : CExceptions("Error! Index is out of range!") {}
CBadDelete::CBadDelete(const char* msg) : CExceptions(msg) {}

CBadInput::CBadInput() : CExceptions("Error! Invalid value!") {}
CBadInput::CBadInput(const char* msg) : CExceptions(msg) {}