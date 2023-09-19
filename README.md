# That is C, baby.  C!

A resource showing that C code has no meaning in itself.

## Description

The very same small C program can be compiled in millions (probably billions)
of different ways so as to exhibit as many different behaviors.
Here you have a short paper and code to explore this fact of life
and reflect on its practical consequences.

## Getting Started

### Dependencies

* GCC/x86 64 version 8, for the original code described in the paper.
* GCC/x86 64 version 9, 10 or 11, for the current code revision.
* [GNU Parallel](https://www.gnu.org/software/parallel/) for testing
  the new code revision in parallel.

### Installing

* Search for the `GCC` environment variable settings in the scripts
  and make sure that variable expands to the driver executable
  of the correct version of the GNU C compiler.

### Executing

* See the paper for instructions about the original version under `src/orig`.
* For the current revision under `src`:
    * For sequential testing: in `test.sh`,
      change the step from `1000` to any value you want in line
      `for value in $(seq 0 1000 "${max}")`,
      then execute the resulting `test.sh` Bourne shell script.
    * For parallel testing: in `test_in_parallel.sh`,
      change the step from `1000` to any value you want in
      `seq 0 100 "${max}"`,
      then execute the resulting `test_in_parallel.sh` Bourne shell script.



## Authors

Roberto Bagnara

## Version History

* 0.2
    * Extended versions exhibiting many more implementation-defined behaviors.
* 0.1
    * Original version as described in <https://arxiv.org/abs/1909.06353>

## License

The C code and scripts are distributed under the MIT License.
See `LICENSE.txt` in directory `src` and its subdirectories
for more information.

The paper can be cited as follows:
```
@Misc{Bagnara19,
  Author = "Roberto Bagnara",
  Title = "That's {C}, baby. {C}!",
  Howpublished = "Report {\tt arXiv:1909.06353 [cs.PL]}",
  Year = 2019,
  Note = "Available at \url{http://arxiv.org/}",
  Abstract = "Hardly a week goes by at BUGSENG without having to
              explain to someone that almost any piece of C text,
              considered in isolation, means absolutely nothing. The
              belief that C text has meaning in itself is so common,
              also among seasoned C practitioners, that I thought
              writing a short paper on the subject was a good time
              investment. The problem is due to the fact that the
              semantics of the C programming language is not fully
              defined: non-definite behavior, predefined macros,
              different library implementations, peculiarities of the
              translation process, \dots: all these contribute to the
              fact that no meaning can be assigned to source code
              unless full details about the build are available. The
              paper starts with an exercise that admits a
              solution. The existence of this solution will hopefully
              convince anyone that, in general, unless the toolchain
              and the build procedure are fully known, no meaning can
              be assigned to any nontrivial piece of C code."
}
```

## Acknowledgments

For useful comments and advice:
* Abramo Bagnara (BUGSENG)
* Paolo Bandini (formerly, University of Parma and BUGSENG)
* Patricia M. Hill (BUGSENG)
* Marcel Beemster (Solid Sands)
* Nicola Vetrini (BUGSENG)
