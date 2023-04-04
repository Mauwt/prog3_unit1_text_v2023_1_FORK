//
// Created by rudri on 10/11/2020.
//

#include <cstring>
#include <iostream>

#ifndef PROG3_UNIT1_TEXT_V2023_1_TEXT_H
#define PROG3_UNIT1_TEXT_V2023_1_TEXT_H

class Text {
private:
    char* _text = nullptr;
    int len = 0;
public:

    Text() = default;

    Text(const Text& other);//Constructor copy
    Text(const char* _str); // Constructor por parametros
    Text(std::string& _str); // Constructor por parametros tipo string
    Text(std::string&& _str); //Constructor por parametros tipo string rvalue
    explicit Text(Text&& other) noexcept; // Constructor move

    virtual ~Text(){
        delete [] _text;
    }
    //Asignación por sobrecarga

    operator std::string() const; // sobercarga para conversiones
    Text& operator=(const Text& other);
    Text& operator=(Text&& other);
    Text& operator = (const std::string& _str);
    Text operator^ (const Text& other);
    Text& operator ^= (Text& other);
    Text& operator ^= (const std::string& _str);
    //std::string& operator =(const Text& text);

    //Funciones amigas
    friend std::istream& getline(std::istream& in, Text& _t);
    friend std::ostream& operator<<(std::ostream& out, const Text& text);
    friend std::istream& operator>>(std::istream& in, Text& text);

};

#endif //PROG3_UNIT1_TEXT_V2023_1_TEXT_H
/*
std::istream& getline(std::istream& in, Text& _t){
    std::string temp;
    std::getline(in, temp);
    _t = temp;
    return in;
}
std::ostream& operator<<(std::ostream& out, const Text& text)
{
    out << std::string(text._text) <<" ";
    return out;
}
std::istream& operator>>(std::istream& in, Text& text){
    std::string _str;
    std::getline(std::cin, _str);

    Text temp(_str);
    text = temp;
    return in;
}

*/