#include<string>
#include <string_view>
#include <vector>
#include <iostream>
#include <fstream>
#include <charconv>

class BigInt;

BigInt operator+(const BigInt &, const BigInt &);

BigInt operator-(const BigInt &, const BigInt &);

BigInt operator*(const BigInt &, const BigInt &);

BigInt operator/(const BigInt &, const BigInt &);

BigInt operator^(const BigInt &, const BigInt &);

BigInt operator%(const BigInt &, const BigInt &);

class BigInt
{
private:
    std::vector<int32_t> number;
    int8_t sign = 1;

    static BigInt convert_dec_to_bin_mod(BigInt decimal_number);

    static BigInt convert_bin_to_dec_mod(BigInt binary_number);

    static BigInt plus_one(BigInt binary_number);

    static BigInt Not(BigInt binary_number);

public:
    BigInt();

    BigInt(int);

    BigInt(std::string);

    BigInt(const BigInt &);

    ~BigInt();

    BigInt &operator=(const BigInt &);

    BigInt operator~() const;

    BigInt &operator++();

    const BigInt operator++(int32_t);

    BigInt &operator--();

    const BigInt operator--(int32_t);

    BigInt &operator+=(const BigInt &);

    BigInt &operator*=(const BigInt &);

    BigInt &operator-=(const BigInt &);

    BigInt &operator/=(const BigInt &);

    BigInt &operator^=(const BigInt &);

    BigInt &operator%=(const BigInt &);

    BigInt &operator&=(const BigInt &);

    BigInt &operator|=(const BigInt &);

    BigInt operator+() const;  // unary +
    BigInt operator-() const;  // unary -

    bool operator==(const BigInt &) const;

    bool operator!=(const BigInt &) const;

    bool operator<(const BigInt &) const;

    bool operator>(const BigInt &) const;

    bool operator<=(const BigInt &) const;

    bool operator>=(const BigInt &) const;

    operator int() const;

    operator std::string() const;

    size_t size() const;
};

BigInt operator+(const BigInt &, const BigInt &);

BigInt operator-(const BigInt &, const BigInt &);

BigInt operator*(const BigInt &, const BigInt &);

BigInt operator/(const BigInt &, const BigInt &);

BigInt operator^(const BigInt &, const BigInt &);

BigInt operator%(const BigInt &, const BigInt &);

BigInt operator&(const BigInt &, const BigInt &);

BigInt operator|(const BigInt &, const BigInt &);

std::ostream &operator<<(std::ostream &output, const BigInt &number);

BigInt pow_bigint(BigInt &base, BigInt &power);