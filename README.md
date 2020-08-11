<h1 align="center">Welcome to Route Planning Project 👋</h1>
<p>
  <a href="LICENSE" target="_blank">
    <img alt="License: MIT" src="https://img.shields.io/badge/License-MIT-yellow.svg" />
  </a>
  <a href="https://twitter.com/mbrsantana" target="_blank">
    <img alt="Twitter: mbrsantana" src="https://img.shields.io/twitter/follow/mbrsantana.svg?style=social" />
  </a>
</p>

> A route planning made on OpenStreetMap using A* search

<img src="map.png" width="600" height="450" />

This repo contains a Route Planning project based on [Open Street Map](https://www.openstreetmap.org/).

## Dependencies for Running Locally
* cmake >= 3.11.3
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 7.4.0
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same instructions as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* IO2D
  * Installation instructions for all operating systems can be found [here](https://github.com/cpp-io2d/P0267_RefImpl/blob/master/BUILDING.md)
  * This library must be built in a place where CMake `find_package` will be able to find it

## Cloning

When cloning this project, be sure to use the `--recurse-submodules` flag. Using HTTPS:
```
git clone https://github.com/zerocoolbr/OpenStreetMap-Route-Planning.git --recurse-submodules
```
or with SSH:
```
git clone git@github.com:zerocoolbr/OpenStreetMap-Route-Planning.git --recurse-submodules
```

## Compiling and Running

### Compiling
To compile the project, first, create a `build` directory and change to that directory:
```
mkdir build && cd build
```
From within the `build` directory, then run `cmake` and `make` as follows:
```
cmake ..
make
```
### Running
The executable will be placed in the `build` directory. From within `build`, you can run the project as follows:
```
./OSM_A_star_search
```
Or to specify a map file:
```
./OSM_A_star_search -f ../<your_osm_file.osm>
```

## Testing

The testing executable is also placed in the `build` directory. From within `build`, you can run the unit tests as follows:
```
./test
```

## Author

👤 **Marcos Santana**

* Twitter: [@mbrsantana](https://twitter.com/mbrsantana)
* Github: [@zerocoolbr](https://github.com/zerocoolbr)
* LinkedIn: [@marcosbrs](https://linkedin.com/in/marcosbrs)

## Show your support

Give a ⭐️ if this project helped you!

## 📝 License

Copyright © 2020 [Marcos Santana](https://github.com/zerocoolbr).<br />
This project is [MIT](LICENSE) licensed.