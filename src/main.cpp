#include <iostream>
#include <simdjson.h>

using namespace simdjson;

int main(int argc, char* argv[]) {

    ondemand::parser parser;
    auto json = padded_string::load("../data/sample.json");
    ondemand::document doc = parser.iterate(json); 

    int64_t foo = doc["foo"];
    auto obj = doc["obj"];
    std::string_view msg = obj["msg"];
    double num = obj["num"];

    auto arr = doc["arr"].get_array();

    std::cout << "foo:" << foo << '\n';
    std::cout << "obj::msg: " << msg << '\n';
    std::cout << "obj::num: " << num << '\n';
    std::cout << "arr: ";
    for (auto e: arr) {
        std::cout << int(e.get_int64()) << ' ';
    }
    std::cout << '\n';
    return 0;
}