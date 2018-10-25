#include "gameexception.hh"

namespace Common
{

GameException::GameException(const std::string& msg): _msg(msg) {}

std::string GameException::msg() const
{

    return _msg;

}

}
