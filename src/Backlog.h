#pragma once

#include <AK/String.h>
#include <AK/Weakable.h>

namespace irc {

class Backlog : public Weakable<Backlog>, String {
};

}