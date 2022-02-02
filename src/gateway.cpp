// Your First C++ Program

#define CROW_MAIN
#include <iostream>
#include "crow.h"
#include "apple_routes_loader.h"

int main() {
    std::cout << "Hello World!";

    crow::App<> app;

    AppleRoutesLoader apple_routes_loader;

    apple_routes_loader.add_routes(app);

    app.port(18080).multithreaded().run();
    return 0;
}
