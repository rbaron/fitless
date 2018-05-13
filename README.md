# fitless

Series of example programs to run on the ID115 fitness tracker. Most examples are based on the ones from the official SDK (version 12), but have been adapted to run on this specific device.

## Running an example

To run, for instance, `blinky/`, do:

```
cd blinky/id115/blank/armgcc
export NRF_SDK12_ROOT=__PATH_TO_YOUR_NRF_SDK_VERSION_12__
make
make flash
make log
```
