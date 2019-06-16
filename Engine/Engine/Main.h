#pragma once

#include "Engine.h"
#include "Util/Log.h"

extern one::Engine* one::Generate();

#ifdef ONE_WINDOW

int main(int argc, char** argv)
{
    /*Initialize Logger System*/
    one::Log::Init();

    auto game = one::Generate();
    game->Run();
    delete game;
}

#endif // ONE_WINDOW
