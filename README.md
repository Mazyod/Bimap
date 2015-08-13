# Bimap

C++ Bimap implementation, header-only, with tests, not efficient nor generic enough, but gets the job done. Contributions welcome.

- I preferred ObjC style methods over operator overloading, so the interface is very explicit.
- Take special care that given a value, and array of keys are returned. (Can't assume that keys have unique values!)

## How To Use

Just include the `Bimap.h` header into your project, and start using!

## Todo

- [ ] Add a freakin namespace

## Contributing

If you hate to use boost as much as me, might as well contribute to this. I would like it to be good enough to be added in [pocoproject](http://pocoproject.org).

I use Catch for testing, and CLion for building. So, dependecies are minimal, and running the tests shouldn't be a catch (pun shamefully intended).
