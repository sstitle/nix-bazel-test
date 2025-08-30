# nix-bazel-test
Testing rules_nixpkgs with Bazel

## Development Setup

This project uses [Nix](https://nixos.org/) for reproducible development environments and [Bazel](https://bazel.build/) for builds.

### Getting Started

1. Enter the Nix development shell:
   ```bash
   nix develop
   ```

2. Build the project:
   ```bash
   bazel build //...
   ```

3. Run the hello application:
   ```bash
   bazel run //app:hello
   ```

## C++ Development with IDE Support

This project is configured with [Hedron's Compile Commands Extractor](https://github.com/hedronvision/bazel-compile-commands-extractor) for excellent C++ IDE support through clangd.

### Generating Compile Commands

To generate `compile_commands.json` for IDE autocomplete, syntax highlighting, and navigation:

```bash
bazel run @hedron_compile_commands//:refresh_all
```

This command:
- Analyzes all C++ targets in the project
- Generates a `compile_commands.json` file in the project root
- Enables clangd-based tools to understand your build configuration

### IDE Setup

#### VS Code with clangd

1. Install the clangd extension:
   ```bash
   code --install-extension llvm-vs-code-extensions.vscode-clangd
   ```

2. Disable the Microsoft C++ extension to avoid conflicts:
   ```bash
   code --uninstall-extension ms-vscode.cpptools
   ```

3. Configure clangd in VS Code settings with these arguments:
   - `--header-insertion=never`
   - `--compile-commands-dir=${workspaceFolder}/`
   - `--query-driver=**`

#### Other Editors

For other editors, install clangd and point it to the `compile_commands.json` file in the project root.

### When to Refresh Compile Commands

Re-run the compile commands extraction when you:
- Add new C++ source files
- Modify BUILD files
- Change dependencies
- Add new targets

The extraction is fast and can be run frequently during development.
