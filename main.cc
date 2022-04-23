#include <sstream>
#include <drogon/drogon.h>

int main(int argc, char *argv[]) {
    int port = 80;

    if (argc >= 2)
    {
        std::istringstream iss(argv[1]);
        int val;

        if (iss >> val)
        {
            port = val;
        }
    }

    std::cout << "Starting app listening port " << port << std::endl;

    //Set HTTP listener address and port
    drogon::app()
        .addListener("0.0.0.0", port)
        .setDocumentRoot("docroot");
    //Load config file
    //drogon::app().loadConfigFile("../config.json");
    //Run HTTP framework,the method will block in the internal event loop
    drogon::app().run();
    return 0;
}
