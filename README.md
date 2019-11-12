sensor-net: A simple sensor edge application
============================================

Building and Testing
-------------------

### Build Requirements

- Building uses [Meson](https://mesonbuild.com)
- Compiling requires [Boost](https://www.boost.org)
- ... and a C++17 compiler

### Initialization

To get started, run:

```
meson build_dir && ninja -C build_dir
```

To create multiple builds do:

```
meson setup --buildtype=release build_release
```

or

```
meson setup --buildtype=debug build_debug
```

### Building and Testing

After initializing, to build and test, run `ninja` by itself. I.e.:

```
ninja -C build_dir test
```

Running sensor-net
------------------

To run, launch the executable normally:

```
./build_dir/sensor_net
```

To terminate `sensor_net`, send a `SIGINT` to the process.  Assuming you've launched the process in a "normal" terminal, just hit `CTRL + C`.
