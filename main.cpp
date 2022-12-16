#include "parser.h"
#include "tuple.h"

int main() {
    std::ifstream in("test.csv");
    std::ofstream out("output.txt");
    CSVParser<int, std::string> parser{in, 0};
    for(auto & iter : parser) {
        out << iter << '\n';
    }
    return 0;
}