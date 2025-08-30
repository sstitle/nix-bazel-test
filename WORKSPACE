workspace(name = "nix_bazel_test")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Import the rules_nixpkgs repository
http_archive(
    name = "io_tweag_rules_nixpkgs",
    sha256 = "0dfbc718e8a6e4b376b9445a1f8dce9330d395dd1a53de6e32ca9b6c6ea56860",
    strip_prefix = "rules_nixpkgs-0.13.0",
    urls = ["https://github.com/tweag/rules_nixpkgs/archive/v0.13.0.tar.gz"],
)

# Import the transitive dependencies of rules_nixpkgs
load("@io_tweag_rules_nixpkgs//nixpkgs:repositories.bzl", "rules_nixpkgs_dependencies")
rules_nixpkgs_dependencies()

# Import nixpkgs repository using our flake
load("@io_tweag_rules_nixpkgs//nixpkgs:nixpkgs.bzl", "nixpkgs_git_repository", "nixpkgs_cc_configure")

# Use nixpkgs from our flake
nixpkgs_git_repository(
    name = "nixpkgs",
    revision = "nixos-unstable",
    sha256 = "",  # This will be filled in by Bazel on first run
)

# Configure CC toolchain from nixpkgs using clang
nixpkgs_cc_configure(
    repository = "@nixpkgs",
    name = "nixpkgs_config_cc",
)

# Import spdlog package from nixpkgs
load("@io_tweag_rules_nixpkgs//nixpkgs:nixpkgs.bzl", "nixpkgs_package")
nixpkgs_package(
    name = "spdlog",
    attribute_path = "spdlog.dev",
    repository = "@nixpkgs",
    build_file_content = """\
cc_library(
    name = "spdlog",
    hdrs = glob(["include/**/*.h"]),
    includes = ["include"],
    defines = [
        "SPDLOG_FMT_EXTERNAL=0",
        "SPDLOG_USE_STD_FORMAT=1",
    ],
    visibility = ["//visibility:public"],
)
""",
) 