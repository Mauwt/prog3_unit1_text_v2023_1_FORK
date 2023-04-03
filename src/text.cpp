//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include "text.h"
using namespace std;

//Cosntructore
Text::Text (const Text& other){
    len = other.len;
    _text = new char[len +1];
    strcpy(_text, other._text);
}

Text::Text (const char* _str){ //Constructor por parametros
    len = strlen(_str);
    _text = new char[len + 1];
    strcpy(_text, _str);
}

Text::Text (std::string& str){
    len = str.length();
    _text = new char[len +1];
    std::strcpy(_text, str.c_str());
}

Text::Text(std::string&& _str){
    len = _str.length();
    _text = new char[len + 1];
    std::strcpy(_text, _str.c_str());
}

Text::Text(Text&& other) noexcept{
    len = other.len;
    std::swap(_text, other._text);
    std::swap(len, other.len);
}

//Asignacion por sobrecarga

Text& Text::operator=(const Text& other) {
    if (this != &other) {
        delete[] _text;
        len = other.len;
        _text = new char[len + 1];
        strcpy(_text, other._text);
    }
    return *this;
}

Text& Text::operator = (std::string& _str){
    delete[] _text;
    len = (int)_str.length();
    _text = new char[len+1];
    std::strcpy(_text, _str.c_str());
    return *this;
}
Text::operator std::string() const {
    return string(_text);
}

//Sobrecarga del operador ^ y ^=

Text Text::operator^(const Text &other) {
    int len2 = len + other.len;
    char* result = new char[len2 + 1];
    strcpy(result, _text);
    strcat(result, other._text);
    Text temp(result);
    delete[] result;
    return temp;
}

Text &Text::operator ^=(Text &other) {
    int len2 = other.len;
    len += len2;
    char* result = new char[len + 1];
    std::strcpy(result, other._text);
    std::strcat(_text, result);
    delete[] result;
    return *this;
}

Text &Text::operator^=(const string &_str) {
    len += _str.length();
    char* temp = new char[len + 1] ;
    std::strcpy(temp, _text);
    std::strcat(temp, _str.c_str());

    delete[] _text;
    _text = new char[len +1];
    std::strcpy(_text, temp);
    delete[] temp;
    return *this;
}








