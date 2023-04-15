# modern-cmake-template

[modern cmake example](https://gitlab.com/CLIUtils/modern-cmake/tree/master/examples/extended-project)

This is an example project using CMake.

The requirements are:

- CMake 3.11 or better; 3.14+ highly recommended.
- A C++17 compatible compiler
- The Boost libararies (header only part is fine)
- Git
- Doxygen (optional)

To configure:

```bash
cmake -S . -B build
```

Add `-GNinja` if you have Ninja.

To build:

```bash
cmake --build build
```

To test (`--target` can be written as `-t` in CMake 3.15+):

```bash
cmake --build build --target test
```

To build docs (requires Doxygen, output in `build/docs/html`):

```bash
cmake --build build --target docs
```

To use an IDE, such as Xcode:

```bash
cmake -S . -B xbuild -GXcode
cmake --open xbuild
```

The CMakeLists show off several useful design patters for CMake.

## cmake-file-api

cmake提供了一个基于文件的api，可以通过客户端获取构建系统的语义化信息，通过json文件保存。
想象一下这样一个场景：在neovim编程中不用新开一个窗口就可以进行构建和运行，同时构建信息和运行结果通过
内置term或quickfix展示。构建命令相对固定:`cmake -GNinja -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -B build`
可以简单通过 `vim.fn.termopen(commands)`
来实现。而target一般位于子文件中，可执行路径也不固定，解决的方法就是通过cmake-file-api
中生成的`target-{target-name}-xxxx.json`文件中的信息来获取。一般来说构建通过quickfix打开便于跳转到出错的文件位置。
而执行过程中可能需要输入所以用内置term。

### 实现

cmake-file-api不会自动生成，也没有指定参数来生成。
生成它的方式是新建特定的文件夹和文件 `mkdir -p <build>/.cmake/api/v1/query`
`touch <build>/.cmake/api/v1/query/codemodel-v2`
**注意**由于是先确定了build路径。所以构筑过程是要指定到相同路径
`cmake -B <build>`
构筑后就会自动生成`<build>/.cmake/api/v1/reply`文件夹和target.json文件。

[neovim插件](https://github.com/Shatur/neovim-cmake)
此插件已经被作者archived了。
