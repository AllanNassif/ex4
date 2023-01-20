

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <iostream>
#include <string>
#include <exception>

class DeckFileNotFound : public std::exception {

public:

    /*
    * C'tor of DeckFileNotFound class
    *
    * @return
    *      A new instance of DeckFileNotFound.
    */
    DeckFileNotFound() : m_error("Deck File Error: File not found") {}

    /*
     * what - exception error message
     * 
     * @return
     * returns the exception error message.
    */
    const char* what() const throw() override{
        return m_error.c_str();
    }

private:
    std::string m_error;

};

class DeckFileFormatError : public std::exception {

public:

    /*
    * C'tor of DeckFileFormatError class
    *
    * @param line - line in file where the error occured. 
    * @return
    *      A new instance of DeckFileFormatError.
    */
    DeckFileFormatError(int line) : m_line(line) 
        ,m_error("Deck File Error: File format error in line " + std::to_string(m_line)) {}

    /*
     * what - exception error message
     * 
     * @return
     * returns the exception error message.
    */
    const char* what() const throw() override{
        return m_error.c_str();
    }

private:

    int m_line;
    std::string m_error;

};


class DeckFileInvalidSize : public std::exception {

public:

    /*
    * C'tor of DeckFileInvalidSize class
    *
    * @param line - line in file where the error occured. 
    * @return
    *      A new instance of DeckFileInvalidSize.
    */
    DeckFileInvalidSize() : m_error("Deck File Error: Deck size is invalid") {}

    /*
     * what - exception error message
     * 
     * @return
     * returns the exception error message.
    */
    const char* what() const throw() override{
        return m_error.c_str();
    }

private:

    std::string m_error;

};

#endif //EXCEPTION_H_