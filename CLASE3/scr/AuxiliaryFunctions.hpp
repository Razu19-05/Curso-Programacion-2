
#ifndef CLASE3_AUXILIARYFUNCTIONS_HPP
#define CLASE3_AUXILIARYFUNCTIONS_HPP

#include "Utils.hpp"
#include "Reviews.hpp"

void open_file_read(ifstream &input, const char *file_name);

void open_file_write(ofstream &output, const char *file_name);

int read_date(ifstream &input);

void qsort(struct Review *reviews, int izq, int der);

#endif //CLASE3_AUXILIARYFUNCTIONS_HPP