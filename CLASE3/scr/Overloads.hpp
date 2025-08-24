
#ifndef CLASE3_OVERLOADS_HPP
#define CLASE3_OVERLOADS_HPP

#include "AuxiliaryFunctions.hpp"
#include "Reviews.hpp"

void operator<<(const char *file_name, struct Reviews &reviews);

void operator>>(ifstream &input, struct Review &review);

void operator<<(struct Reviews &reviews, const char *file_name);

void operator<<(ofstream &output, const struct Review review);

void operator +=(struct Reviews &reviews, int* estadisticas);


#endif //CLASE3_OVERLOADS_HPP