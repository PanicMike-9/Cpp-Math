// not official functions, just learning to turn
// math eqations into code
#include <print>

void multiplication_of_matrix()
{
    constexpr int n {3};

    int mat_a[n][n]
    {
        {3, 0, 0},
        {0, 3, 0},
        {0, 0, 3}
    };

    int mat_b[n][n]
    {
        {0, 0, 2},
        {0, 2, 0},
        {2, 0, 0}
    };

    int mat_c[n][n] {};

    for (int k {}; k < n; ++k)
    {
        for (int i {}; i < n; ++i)
        {
            for (int j {}; j < n; ++j)
            {
                mat_c[i][j] += mat_a[i][k] * mat_b[k][j];
            }
        }
    }

    for (int i {}; i < n; ++i)
    {
        for (int j {}; j < n; ++j)
        {
            std::print("{} ",mat_c[i][j]);
        }
        std::println();
    }
}

int main()
{
    multiplication_of_matrix();
}

void trace_of_matrix()
{
    constexpr int n {10};

    int mat[n][n]
    {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    int mat_sum {};

    for (int i {}; i < n; ++i)
    {
        mat_sum += mat[i][i];
    }

    std::println("Identity Matrix sum: {}", mat_sum);
}
