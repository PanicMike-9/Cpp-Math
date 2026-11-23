# Understanding Intel Intrinsics and CPU architecture

## Scalar Data & Packed Data
Processors that support **SSE (Steaming SIMD Extension)** functions, has 16 additional 128-bit registers, which are `xmm0`-`xmm15`.
The `xmm` registers can contain **Scalar data** or **Packed data**.

* **Scalar data**
    > With scalar data, it means just one value. Meaning a single `xmm` register, say `xmm0` register can hold one scalar value.
* **Packed data**
    > The register `xmm0` can also store multiple values, which is called packed data.

* Storing values in `xmm` registers:
    > Two 64-bit **double-precision** floating-point numbers
    > Four 32-bit **single-precision** floating-point numbers
    > Two 64-bit integers
    > Four 32-bit integers
    > Eight 16-bit short integers
    > Sixteen 8-bit bytes or characters

## AVX (Advanced Vector Extenions)
Which is an extension of SSE, AVX registers are double the size of `xmm`, they are called `ymm` registers, which contain 32 additional 256-bit registers, which are `ymm0`-`ymm31`.

## Function naming conventions

Function names like `_mm_mul_ps` or `_mm256_mul_ps`
