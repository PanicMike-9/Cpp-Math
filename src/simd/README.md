# Understanding Intel Intrinsics and CPU architecture

## Scalar Data & Packed Data
Processors that support **SSE (Steaming SIMD Extension)** functions, has 16 additional 128-bit registers, which are `xmm0`-`xmm15`.
The `xmm` registers can contain **Scalar data** or **Packed data**.

* **Scalar data**
    - With scalar data, it means just one value. Meaning a single `xmm` register, say `xmm0` register can hold one scalar value.
* **Packed data**
    - The register `xmm0` can also store multiple values, which is called packed data.

* Storing values in `xmm` registers
    - Two 64-bit **double-precision** floating-point numbers
    - Four 32-bit **single-precision** floating-point numbers
    - Two 64-bit integers
    - Four 32-bit integers
    - Eight 16-bit short integers
    - Sixteen 8-bit bytes or characters

## AVX (Advanced Vector Extenions)
Which is an extension of SSE, AVX registers are double the size of `xmm`, they are called `ymm` registers, which contain 16 additional 256-bit registers, which are `ymm0`-`ymm15`.

## AVX-1 & AVX-2
AVX-1: 128-bit registers which equals to 16 bytes.
AVX-2: 256-bit registers which equals to 32 bytes.

* Numerical processing
    - AVX-1: 4 * 32-bit float or int values
    - AVX-2: 8 * 32-bit values

## Function naming conventions

* Prefix
    - `__m128`: 128-bit registers (4 floats)
    - `__m256`: 256-bit registers (8 floats)

    - `__m128i`: 128-bit registers (4 ints)
    - `__m256i`: 256-bit registers (8 ints)

    - `__m128d`: 128-bit registers (2 double)
    - `__m256d`: 256-bit registers (4 double)

* Suffix
    - `_ps`: packed-single-precision (float)
    - `_pd`: packed-double-precision (double)

