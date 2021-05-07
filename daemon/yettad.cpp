#include <yetta-daemon.h>

int main(int argc, char *argv[])
{
    YettaDaemon app (argc, argv, "yettad");

    return app.exec();
}
