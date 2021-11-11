
#define CROW_MAIN
#include <iostream>
#include "crow.h"

class AppleRoutesLoader {
    public:
        template <typename ... Middlewares>
        void add_routes(crow::App<Middlewares...> &app) {

            CROW_ROUTE(app,"/hello2/<int>")
            ([](int count){
                return crow::response(std::to_string(count));
            });


        }
    private:
};
