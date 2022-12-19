#include <iostream>
#include "parser.h"
#include "tuple.h"

int main() {
    try
    {
        std::ifstream in("test.csv");
        std::ofstream out("output.txt");
        in.exceptions(std::ifstream::badbit | std::ifstream::failbit);

        CSVParser<int, std :: string> parser{in, 0};
        for (auto &iter: parser)
        {
            out << iter << '\n';
        }

        in.close();
        out.close();
    }
    catch (const std::invalid_argument & ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    catch (std::ifstream::failure & ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    return 0;
}