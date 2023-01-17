# Buffer Overflow

> C/C++



Buffer overflow basically voilates the assumptions of a programmer. Many C and C++ memory or string manipulation functions do not rely on the bounds check. A **mistaken size** or **mistaken memory manipulation** leads to piece of code that is the cause of Buffer overflow errors.



In this article let us see the buffer overflows of `memcpy` function.

 

## memcpy

The use of this function is to copy `n` bytes from `source` memory location into the `destination` memory:-

```c
memcpy(destination, source, n);
```

A buffer overflow occurs when we do not respect the *"available"* destination size. Consider the code block below:

```c
memcpy(output, input, sizeof(input));
```

The code above will lead to the following error:

> Memory copy function overflows the destination buffer



The reason is quite simple as we aren't considering the available size in `output` and *assuming* we have *atleast* `sizeof(input)` bytes available in `output` 

Consider the code block below:

```cpp
memcpy(output, input, 10);
```

Again we will get the same error since we are assuming that the size of `output` is  *atleast* 10 bytes.




