#ifndef CLASEDEINTRODUCCION_FUNCIONS_HPP
#define CLASEDEINTRODUCCION_FUNCIONS_HPP
#include "Utils.hpp"

void print_line(size_t, char);
bool get_next_token(const char* input, char* word);
char* get_next_token(const char* input_string);
void tokenize(const char* input_string, int,  bool = false);

#endif //CLASEDEINTRODUCCION_FUNCIONS_HPP