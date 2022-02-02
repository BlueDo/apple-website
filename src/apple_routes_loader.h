
#define CROW_MAIN
#include <iostream>
#include "crow.h"

class AppleRoutesLoader {

    private:
        int tally_count = 0;
    public:
        void add_routes(crow::SimpleApp &app) {

            CROW_ROUTE(app, "/")([](){
                return "Hello world";
            });

            CROW_ROUTE(app,"/hello/<int>")
            ([](int count){
                return crow::response(std::to_string(count));
            });

            CROW_ROUTE(app,"/tally")
            ([&tally_count = this->tally_count](){
                tally_count++;
                return crow::response(std::to_string(tally_count));
            });

        }
    private:
};
