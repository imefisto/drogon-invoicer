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

    drogon::app()
        .addListener("0.0.0.0", port)
        .setDocumentRoot("docroot")
        .createDbClient("sqlite3", "", 3306, "", "", "", 5, "invoicer.db");

    drogon::app().run();
    return 0;
}
