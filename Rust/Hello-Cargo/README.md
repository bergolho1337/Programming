The 'cargo' command helps you build and compile Rust source codes.

It is similar to a 'Makefile' or 'CMakeLists.txt' in C/C++.

# Commands for cargo

## Create a new Rust project

```sh
$ cargo new <name_project>
```

## Build a project

```sh
$ cargo	build
```

By default the project is compiled under DEBUG mode, which might be slower in some cases.
This command also generates an executable at 'target/debug'.

## Build and run a project

```sh
$ cargo	run
```

Similar to the 'build' command, but just after the compilation we run the executable.

## Compile a project

```sh
$ cargo	check
```

This command only compiles the source code and it will not generate an executable. 
Normally, when building a project we run 'check' several times to improve development time.
When the source code is free of compilation errors, then we build and execute our program with the 'build' or 'run' commands.

## Build for release

```sh
$ cargo build --release
```

When your project is finally ready for release, you can use cargo 'build --release' to compile it with optimizations.

