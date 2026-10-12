#include <iostream>
#include "vector2.hpp"

using vec2 = geom::Vector2;

void test_length()
{
    vec2 test_vec(3.0f, 4.0f);
    std::cout << "test length\n"
              << "x: " << test_vec.x << '\n'
              << "y: " << test_vec.y << '\n'
              << "length: " << test_vec.length() << '\n'
              << "length squared: " << test_vec.length_squared() << '\n';
}

void test_normalize()
{
    float x = 3.0f, y = 4.0f;

    vec2 my_vec(x, y);

    vec2 my_vec_norm = my_vec.normalize();
    std::cout << "normalized\n" 
              << "x: " << my_vec_norm.x << ' ' 
              << "y: " << my_vec_norm.y << '\n';
}

void test_dot_product()
{
    vec2 v1(1.0f, 3.0f);
    vec2 v2(4.0f, -2.0f);

    float dot_result = dot(v1,v2);
    float dist = distance(v1, v2);
    float dist_sqr = distance_squared(v1, v2);

    float len = v1.length();
    float len_sqr = v1.length_squared();

    std::cout << "dot product: " <<  dot_result << '\n';
    std::cout << "distance : " << dist << '\n';
    std::cout << "distance squared : " << dist_sqr << '\n';
    std::cout << "length : " << len << '\n';
    std::cout << "length squared : " << len_sqr << '\n';
}

void test_operator_overloads()
{
    vec2 v3(10.0f, 100.0f);
    vec2 v4(5.0f, 50.0f);

    vec2 div_eql = v4 /= v3;
    std::cout << "divide equal /=\n"
              << "x: " << div_eql.x << '\n'
              << "y: " << div_eql.y << '\n';

    vec2 v5(10.0f, 20.0f);
    vec2 v6(10.0f, 20.0f);
    float div_by = 2.0f;

    vec2 div_vec = component_div(v5, v6);
    std::cout << "divide /\n"
              << "x: " << div_vec.x << '\n'
              << "y: " << div_vec.y << '\n';
    std::cout << "divide by scalar /\n"
              << "x: " << div_vec.x/div_by << '\n'
              << "y: " << div_vec.y/div_by << '\n';

    std::cout << "is v5 != v6\n"
              << (v5 != v6 ? "they are not equal" : "they are equal") << '\n';
    std::cout << "is v3 != v4\n"
              << (v3 != v4 ? "they are not equal" : "they are equal") << '\n';

    v5 = -v3;
    std::cout << "unary minus \n"
              << "v5.x: " << v5.x << '\n'
              << "v5.y: " << v5.y << '\n';
}

void test_rotate()
{
    vec2 v1(10.0f, 20.0f);
    vec2 v2(5.0f, 10.0f);

    float angle = 10; // 10 degrees

    vec2 v1_rot = v1.rotate(angle);
    vec2 v2_rot = v2.rotate(angle);

    std::cout << "Initial Vector values\n" 
              << "v1 x: " << v1.x << '\n'
              << "v1 y: " << v1.y << '\n'
              << "v2 x: " << v2.x << '\n'
              << "v2 y: " << v2.y << '\n';

    std::cout << "Rotate by angle: " << angle << '\n';

    std::cout << "Rotated vector values\n"
              << "v1_rot x: " <<  v1_rot.x << '\n'
              << "v1_rot y: " <<  v1_rot.y << '\n'
              << "v2_rot x: " <<  v2_rot.x << '\n'
              << "v2_rot y: " <<  v2_rot.y << '\n';
}

int main()
{
//    std::cout << "=================== test_length() ===================\n";
//    test_length();
//    std::cout << "=================== test_normalize() ===================\n";
//    test_normalize();
//    std::cout << "=================== test_dot_product() ===================\n";
//    test_dot_product();
//    std::cout << "=================== test_operator_overloads() ===================\n";
//    test_operator_overloads();
//    std::cout << "=================== end ===================\n";
    test_rotate();
    return 0;
}
