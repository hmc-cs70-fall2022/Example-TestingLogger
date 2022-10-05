# `TestingLogger` Example

This GitHub repositor provides an introduction to the `make` tool.

## Examine, Compile and Run the Code

Load the code in _Visual Studio Code_ and briefly look over the code in `example.cpp`.

Then, in the terminal (using CS 70 docker image), run `make` or `cs70-make` to build the code.

Then run it with `./example`.  (Remember to scroll back up to see all the output if you're viewing it in a small window.)

## `affirm`

The first two examples (`test1` and `test2`) use `affirm`, which takes a boolean argument. The test passes if the boolean is true, and fails if it is false.  (If you've seen `assert` in C, `affirm` is similar, although it does not stop the program if the test fails, it just logs the failure, recording where in the program the failure occurred, including the function and line number.)

Notice that when tests pass, as in `test1`, the `affirm` doesn't print anything and `log.summarize()` just prints a short message that the test passed.

In `test2` on the other hand, the failed `affirm` produces the message

```
FAILURE (after 4 passes): example.cpp:23:       i < MAX
```

It shows you which line of the file the problem was, and what the code that produced a false value was.  It will only print this message once however (the first time it fails).  Subsquent failures will be noted in the summary.

When a test fails, the summary is more detailed, showing you a list of all the failures:

```
Summary of affirmation failures for test 2
----
Fails   / Total Issue
1       / 5     example.cpp:23: i < MAX
```

## `affirm_expected`

The next two examples (`test3` and `test4`) use `affirm_expected`, which takes two arguments: an expression and an expected result.  The test passes if the expression is equal to the expected result.  If they aren't equal, the test fails, and the message shows you what the expression evaluated to, and what the expected result was.

In `test3`, the expression `1 + 1` is equal to the expected result, `2`, so the test passes.

In `test4`, the expression `i * i` evaluates to `1`, but the expected result was `2`.  The message shows you the actual value and the expected value:

```
FAILURE (after 1 passes): example.cpp:43:       val, expecting 2*i
        actual:   1
        expected: 2
```

If the types being tested do not support printing (via `operator<<`), `affirm_expected` still works, but the actual/expected values are not shown.

### Testing Output

So far, our examples of `affirm_expected` are just testing the value of an expression. Sometimes, however, we want to print something and see if it looks the way it is supposed to. We can achieve this goal by using C++'s `std::stringstream` class.

Normally C++'s I/O streams read or write text fron/to files or to our terminal, but a `std::stringstream` instead targets an internal `std::string` object. When we write to a `std::stringstream` with `<<`, it adds our printed output characters to this string. `std::stringstream`'s `str()` function returns the contents of this string object.

In `test5`, we print a string and a number to `ss` (which is a `std::stringstream`) . We then use `ss.str()` in `affirm_expected` to check that the string is what we expect it to be.


## `log.summarize()`

Every testing function ends with a call to the `summarize()` member function of our `TestingLogger` instance. This function returns `true` if the all the tests passed, and `false` if any failed.  It also prints a summary of the test.  The summary is more detailed if the test failed.

This function has an optional `bool` parameter (that defaults to `false`). Passing `true` causes it to produce a detailed summary regardless of whether any tests failed or not.  We use that in `main` to get the detailed summary that includes tests where everything passed.

## `TestingLogger`

The `TestingLogger` class is the class that actually tracks all all the passed and failed affirmations and knows the name of the set of tests being worked on.

If you create a `TestingLogger` when one already exists in an outer function, its overall performance (total tests and total fails) will be logged into the outer logger.  That is why `main` produced the output

```
Summary of affirmation failures for all tests
----
Fails   / Total Issue
0       / 1     [test 1]
1       / 5     [test 2]
0       / 1     [test 3]
1       / 4     [test 4]
```

## Conclusion

The `TestingLogger` framework is specific to CS 70.  There are other testing frameworks for C++, but most of them have so many features that there is a lot to learn, and we want to focus on writing good test cases, not how to use a complicated testing framework.  With `TestingLoger`, most of the time `affirm_expected` is all you need. 
