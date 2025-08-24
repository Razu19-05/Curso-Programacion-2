
#ifndef CLASE3_AUXILIARYFUNCTIONS_HPP
#define CLASE3_AUXILIARYFUNCTIONS_HPP

#include "Utils.hpp"

void open_file_read(ifstream &input, const char *file_name);

void open_file_write(ofstream &output, const char *file_name);

int read_date(ifstream &input);

#endif //CLASE3_AUXILIARYFUNCTIONS_HPP