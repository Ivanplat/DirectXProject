#pragma once
#include "DIHeader.h"
#include <exception>
#include <string>

class ExceptionHandler : public std::exception
{
public:
	ExceptionHandler(int line, const char* file) noexcept;
	virtual const LPCSTR lwhat() const noexcept;
	const char* what() const noexcept override;
	virtual const LPCSTR GetType() const noexcept;
	int GetLine() const noexcept;
	const std::string& GetFile() const noexcept;
	std::string GetOriginString() const noexcept;
private:
	int line;
	std::string file;
protected:
	mutable std::string whatBuffer;
};

