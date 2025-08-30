//
// Created by Huarote on 22/08/2025.
//

#ifndef CLASE3_REVIEWS_HPP
#define CLASE3_REVIEWS_HPP
#include "Review.hpp"

struct Reviews {
    struct Review reviews[REVIEWS_MAX];
    int n_reviews; //Cantidad real de datos
    int n_negatives;
    int n_positives;
    int n_neutrals;
};

#endif //CLASE3_REVIEWS_HPP