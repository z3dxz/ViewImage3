# View Image 3
This is the upcoming rewrite of the **cosine64.com** image viewer

# The Real Deal

The old viewer's code was extremely hard to read and was a mess. This code is going to be properly object-oriented with the necessary abstraction to ensure optimal stability

## Why?

This image viewer is going to be hardware-accelerated, support high-dpi, and be cross-platform
The old viewer was completely software rendered, had no high-dpi support, and only worked on Windows.

## How

The old viewer was written using the **Win32 API** which was painful and slow, as well as being exclusive to windows
This new image viewer is going to be written mostly in **SFML** which is cross-platform, hardware accelerated, and produce cleaner code

# Compatibility

Compatibility will become slightly more strict, however.
Windows XP will be very difficult to support so it is undecided whether or not it is going to be supported
Linux shall be 100% be supported
Some older computers may run the software faster due to it's increased optimization

# Compilation

Dependencies:
- CMake
- Standard C++
- SFML