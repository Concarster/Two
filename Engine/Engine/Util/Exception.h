#pragma once
#include <string>
namespace one
{
	class Exception
	{
	public:
		Exception(const std::string &Message) : reason(Message) {};
		const std::string reason;
	};
}
