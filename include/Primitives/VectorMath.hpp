#ifndef VECTORMATH_HPP_INCLUDED
#define VECTORMATH_HPP_INCLUDED
#include <Primitives/Vector2.hpp>
#include <Primitives/Matrix.hpp>

template <class T>
double dotProduct( Vector2<T>& vec1, Vector2<T>& vec2 ) {
    return vec1.x * vec2.x + vec1.y * vec2.y;
}

template <class T>
double magnitude( Vector2<T>& vec ) {
    return sqrt( vec.x * vec.x + vec.y * vec.y );
}

template <class T>
void normalizeVector( Vector2<T>& vec ) {
    vec/=magnitude(vec);
}

template <class T>
Vector2<T> giveNormalizedVector( Vector2<T>& vec ) {
    return Vector2<T>(vec/magnitude(vec));
}

template <class T>
void rotateVector( Vector2<T>& vec, float angle ) {
    vec = Vector2<T>( vec.x * cos( angle ) - vec.y * sin( angle ), vec.x * sin( angle ) + vec.y * cos( angle ) );
}

template <class T>
void rotateVectorRight( Vector2<T>& vec ) {
    vec.x *= -1;
}

template <class T>
float crossProduct( Vector2<T> vec1, Vector2<T> vec2 ) {
    return vec1.x * vec2.y - vec1.y * vec2.x;
}

template <class T>
Vector2<T> projectVector( Vector2<T> vectorToProject, Vector2<T> vectorProjectedOnTo ) {

    /* Projects a onto b in the form of
    b(dot(a,b)/(||b||^2)
    */

    return vectorProjectedOnTo*(dotProduct(vectorToProject, vectorProjectedOnTo ))/(pow(magnitude(vectorProjectedOnTo),2.0));
}

#endif // VECTORMATH_HPP_INCLUDED
