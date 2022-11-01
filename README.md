# pptest

An abstract reporting header-only unit-testing library for C++.

*STATUS:* in-development

## target requirements

- Easy to learn and use.
- No internal dynamic allocations.
- The user decides whether and how to store test results.
- Separate layer of implementation for presentation of test results.
- Mutlithread friendly. i.e. separate instances on separate threads should have no issues.
- Helper macros for Tests, Testcases and Assertions.
- snake-case aliases for usable types and defs.
