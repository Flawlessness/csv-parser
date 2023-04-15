#pragma once

#include "tuple.h"

template<class... Args>
class CSVParser {
public:
    class Iterator {
        std::ifstream *input;
        size_t pos = 0;
        std::tuple<Args...> string_tuple;
    public:
        explicit Iterator(std::ifstream *in) : input(in)
        {
            if(in != nullptr)
            {
                (*in) >> string_tuple;
                if(input->eof())
                {
                    input = nullptr;
                }
            }
            else
            {
                pos = -1;
            }
        }
        ~Iterator() = default;
        bool operator!=(const Iterator &a) const;
        Iterator &operator++();
        std::tuple<Args...> &operator*();
        std::tuple<Args...> *operator->();
    };

    CSVParser(std::ifstream &in, int skip);

    Iterator begin();
    Iterator end();

private:
    std::ifstream *input;
};

template<class... Args>
CSVParser<Args...>::CSVParser(std::ifstream &in, int skip) {
    std::string str;
    for (int index = 0; index < skip; index++)
    {
        getline(in, str);
    }
    input = &in;
}

template<class... Args>
bool CSVParser<Args...>::Iterator::operator!=(const typename CSVParser<Args...>::Iterator &a) const {
    return (input != a.input) || (pos != a.pos);
}

template<class... Args>
typename CSVParser<Args...>::Iterator &CSVParser<Args...>::Iterator::operator++() {
    if(input == nullptr)
    {
        pos = -1;
        return *this;
    }
    (*input) >> string_tuple;
    if(input->eof())
    {
        pos++;
        input = nullptr;
        return *this;
    }
    pos++;
    return *this;
}

template<class... Args>
std::tuple<Args...> &CSVParser<Args...>::Iterator::operator*() {
    return string_tuple;
}

template<class... Args>
std::tuple<Args...> *CSVParser<Args...>::Iterator::operator->() {
    return &string_tuple;
}

template<class... Args>
typename CSVParser<Args...>::Iterator CSVParser<Args...>::begin() {
    return Iterator(input);
}

template<class... Args>
typename CSVParser<Args...>::Iterator CSVParser<Args...>::end() {
    return Iterator(nullptr);
}
