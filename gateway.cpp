// Your First C++ Program

#define CROW_MAIN
#include <iostream>
#include "crow.h"
#include "apple_routes_loader.h"

template <typename ... Middlewares>
void add_routes(crow::App<Middlewares...> &app) {

    // int a =1;
    // app.port(1);
    // CROW_ROUTE(app,"/");
    app.route<crow::black_magic::get_parameter_tag("/")>("/");
    // ([](){
    //     return "Hello world";
    // });


}

void add_routes2(crow::SimpleApp &app) {

    // CROW_ROUTE(app,"/hello3/<int>")
    app.route<crow::black_magic::get_parameter_tag("/hello3/<int>")>("/hello3/<int>")
    ([](int count){
        return crow::response(std::to_string(count));
    });


}

int main() {
    std::cout << "Hello World!";

    crow::App<> app;

    AppleRoutesLoader apple_routes_loader;

    CROW_ROUTE(app, "/")([](){
        return "Hello world";
    });

    CROW_ROUTE(app,"/hello/<int>")
    ([](int count){
        return crow::response(std::to_string(count));
    });

    int tally_count = 0;

    CROW_ROUTE(app,"/tally")
    ([&tally_count](){
        tally_count++;
        return crow::response(std::to_string(tally_count));
    });

    // apple_routes_loader.add_routes(app);
    add_routes(app);
    add_routes2(app);

    app.port(18080).multithreaded().run();
    // return 0;
}
