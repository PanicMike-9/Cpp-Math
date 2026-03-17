#include <iostream>
#include <string>
#include "vector2.hpp"

void test_length()
{
    Vector2 test_vec(3.0f, 4.0f);
    std::cout << "test length\n"
              << "x: " << test_vec.x << '\n'
              << "y: " << test_vec.y << '\n'
              << "length: " << test_vec.length() << '\n'
              << "length squared: " << test_vec.length_squared() << '\n';
}

void test_normalize()
{
    float x = 3.0f, y = 4.0f;

    Vector2 my_vec(x, y);

    Vector2 my_vec_norm = my_vec.normalize();
    std::cout << "normalized\n" 
              << "x: " << my_vec_norm.x << ' ' 
              << "y: " << my_vec_norm.y << '\n';
}

void test_dot_product()
{
    Vector2 v1(1.0f, 3.0f);
    Vector2 v2(4.0f, -2.0f);

    float dot_result = v1.dot(v2);
    float dist = v1.distance(v2);
    float dist_sqr = v1.distance_squared(v2);
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
    Vector2 v3(10.0f, 100.0f);
    Vector2 v4(5.0f, 50.0f);

    Vector2 div_eql = v4 /= v3;
    std::cout << "divide equal /=\n"
              << "x: " << div_eql.x << '\n'
              << "y: " << div_eql.y << '\n';

    Vector2 v5(10.0f, 20.0f);
    Vector2 v6(10.0f, 20.0f);
    float div_by = 2.0f;

    Vector2 div_vec = v5/v6;
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

int main()
{
    std::cout << "=================== test_length() ===================\n";
    test_length();
    std::cout << "=================== test_normalize() ===================\n";
    test_normalize();
    std::cout << "=================== test_dot_product() ===================\n";
    test_dot_product();
    std::cout << "=================== test_operator_overloads() ===================\n";
    test_operator_overloads();
    std::cout << "=================== end ===================\n";
    return 0;
}
