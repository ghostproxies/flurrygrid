# FlurryGrid™

[![FlurryGrid™](https://repository-images.githubusercontent.com/1194805912/01112525-7c4b-47cd-804d-2a15382bf465)](https://github.com/ghostproxies/flurrygrid)

## Table of Contents

- [Introduction](README.md?tab=readme-ov-file#introduction)
- [Author](README.md?tab=readme-ov-file#author)
- [License](README.md?tab=readme-ov-file#license)
- [Reference](README.md?tab=readme-ov-file#reference)

## Introduction

FlurryGrid™ is the hyper-efficient 64-bit PRNG for 256-bit output.

In further detail, FlurryGrid™ is a non-cryptographic PRNG (for 64-bit architecture) that has 256 bits of output (for each `flurrygrid` result), [PulseField™](https://github.com/ghostproxies/pulsefield), a minimum period of at least 2⁶⁴, excellent statistical test results, hyper-fast speed and reversibility.

## Author

FlurryGrid™ was created by [William Stafford Parsons](https://github.com/williamstaffordparsons) as a product of [GhostProxies](https://ghostproxies.com).

## License

FlurryGrid™ is licensed with the [BSD-3-Clause](LICENSE) license.

## Reference

FlurryGrid™ was implemented in C (requiring the `stdint.h` header to define a 64-bit, unsigned integral type for `uint64_t`).

[flurrygrid.c](flurrygrid.c)

The `flurrygrid` function modifies the state in a `struct flurrygrid_state` instance to generate 4 pseudorandom `uint64_t` integers in the `output` array.

Each state variable (`a`, `b`, `c` and `d`) in a `struct flurrygrid_state` instance must be seeded (before generating a deterministic FlurryGrid™ sequence that must discard the first few `flurrygrid` results).

FlurryGrid™ uses [PulseField™](https://github.com/ghostproxies/pulsefield) to generate deterministic sequences that each have a minimum period of at least 2⁶⁴.

As specified by [PulseField™](https://github.com/ghostproxies/pulsefield), FlurryGrid™ can generate up to 2⁶⁴ parallel instances that each avoid full state collisions (for at least 2⁶⁴ `flurrygrid` results) among the set of parallel instances.

FlurryGrid™ yields excellent results in the latest stringent statistical test suites such as Dieharder 3.31.1, NIST STS, TestU01 1.2.3 BigCrush (using the 256-bit output as 8 32-bit integers) and PractRand 0.96.

Each of the following PRNG speed test results log the fastest process execution speed (from an AMD A4-9120C) among several repetitions of a test that generates (and hashes) 1 billion pseudorandom `uint64_t` integers in a `#pragma GCC unroll 0` loop.

| PRNG | Milliseconds |
| --- | --- |
| **`flurrygrid`** (`gcc -O3`) | **642ms** |
| [`recoilfuse`](https://github.com/ghostproxies/recoilfuse) (`gcc -O3`) | 806ms |
| `shishua_avx2` (`gcc -O3 -mavx2`) | 866ms |
| `shishua_sse4` (`gcc -O3 -msse4`) | 978ms |
| `shishua_sse3` (`gcc -O3 -msse3`) | 1147ms |
| `shishua_sse2` (`gcc -O3 -msse2`)| 1154ms |
| `shishua` (`gcc -O3`) | 2251ms |
| `sfmt` (`gcc -O3 -msse2`) | 5525ms |
