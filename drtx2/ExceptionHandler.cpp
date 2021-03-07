#include "ExceptionHandler.h"
#include <sstream>


ExceptionHandler::ExceptionHandler(int line, const char* file) noexcept : line(line), file(file){}

const LPCSTR ExceptionHandler::lwhat() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl << GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* ExceptionHandler::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl << GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const LPCSTR ExceptionHandler::GetType() const noexcept
{
	return "Exc";
}

int ExceptionHandler::GetLine() const noexcept
{
	return line;
}

const std::string& ExceptionHandler::GetFile() const noexcept
{
	return file;
}

std::string ExceptionHandler::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[FILE]: " << file << std::endl << "[LINE]: " << line;
	return oss.str();
}

