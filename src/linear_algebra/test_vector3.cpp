#include <iostream>
#include <print>
#include <format>
#include "vector3.hpp"

using vec3 = geom::Vector3;
using std::println;
using std::print;

inline void test_length()
{
    vec3 test_vec(3.0f, 4.0f, 1.0f);
    println("Test Length");
    print
    (
      "x: {:2.2f}\n" 
      "y: {:2.2f}\n"
      "z: {:2.2f}\n", 
      test_vec.x, test_vec.y, test_vec.z
    );
    println("Length: {}", test_vec.length());
    println("Length Squared: {}", test_vec.length_squared());
}

inline void test_normalize()
{
    float x = 3.0f, y = 4.0f, z = 1.0f;

    vec3 my_vec{x, y, z};

    vec3 my_vec_norm = my_vec.normalize();
    println("Test Normalize");
    print
    (
      "x: {:2.2f}\n" 
      "y: {:2.2f}\n" 
      "z: {:2.2f}\n", 
      my_vec_norm.x, my_vec_norm.y, my_vec_norm.z
    );
}

inline void test_dot_product()
{
    vec3 v1(1.0f, 3.0f, 1.0f);
    vec3 v2(4.0f, -2.0f, 1.0f);

    float dot_result = dot(v1,v2);
    float dist = distance(v1, v2);
    float dist_sqr = distance_squared(v1, v2);

    float len = v1.length();
    float len_sqr = v1.length_squared();

    print
    (  
      "v1.x: {:2.2f}\n" 
      "v1.y: {:2.2f}\n" 
      "v1.z: {:2.2f}\n", 
      v1.x, v1.y, v1.z
    );

    print
    (  
      "v2.x: {:2.2f}\n" 
      "v2.y: {:2.2f}\n" 
      "v2.z: {:2.2f}\n",
      v2.x, v2.y, v2.z
    );

    print
    (
      "Dot:              {:8.2f}\n" 
      "Distance:         {:8.2f}\n" 
      "Distance Squared: {:8.2f}\n"
      "Length:           {:8.2f}\n" 
      "Length Squared:   {:8.2f}\n", 
      dot_result, dist, dist_sqr, len, len_sqr
    );
}

inline void test_operator_overloads()
{
    vec3 v3(10.0f, 100.0f, 1.0f);
    vec3 v4(5.0f, 50.0f, 1.0f);

    vec3 div_eql = component_div(v3, v4);
    print
    (
       "Component Division\n"
       "x: {:2.2f}\n"
       "y: {:2.2f}\n"
       "z: {:2.2f}\n",
       div_eql.x, div_eql.y, div_eql.z
    );

    vec3 v5(10.0f, 20.0f, 1.0f);
    vec3 v6(10.0f, 20.0f, 1.0f);
    float div_by = 3.0f;

    vec3 div_vec = component_div(v5, v6);
    print
    (
       "Division\n"
       "x: {:2.2f}\n"
       "y: {:2.2f}\n"
       "z: {:2.2f}\n",
       div_vec.x, div_vec.y, div_vec.z
    );
    print
    (
       "Divide by Scalar\n"
       "x: {:2.2f}\n"
       "y: {:2.2f}\n"
       "z: {:2.2f}\n",
       div_vec.x/div_by, div_vec.y/div_by, div_vec.z/div_by
    );
    print
    ( 
       "v5 != v6? "
       "{}\n"
       "v3 != v4? "
       "{}\n",
       v5 != v6 , v3 != v4 
    );

    v5 = -v3;
    print
    (
       "Unary Minus\n"
       "v5.x: {:2.2f}\n"
       "v5.y: {:2.2f}\n"
       "v5.z: {:2.2f}\n",
       v5.x, v5.y, v5.z
    );
}

int main()
{
    test_length();
    test_normalize();
    test_dot_product();
    test_operator_overloads();
    return 0;
}
