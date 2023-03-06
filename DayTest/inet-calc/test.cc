#include <iostream>
#include <jsoncpp/json/json.h>

typedef struct request{
    int x;
    int y;
    char op;    // "+-*/%"
}request_t;

int main()
{
    request_t req = {10, 20, '*'};
    Json::Value root;
    root["x"] = req.x;
    root["y"] = req.y;
    root["op"] = req.op;

    Json::FastWriter writer;
    std::string str = writer.write(root);

    std::cout << str.c_str() << std::endl;

    return 0;
}

