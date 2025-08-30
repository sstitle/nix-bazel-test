workspace(name = "nix_bazel_test")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Import the rules_nixpkgs repository
http_archive(
    name = "io_tweag_rules_nixpkgs",
    sha256 = "",
    strip_prefix = "rules_nixpkgs-0.12.0",
    urls = ["https://github.com/tweag/rules_nixpkgs/archive/v0.12.0.tar.gz"],
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
    attribute_path = "clang",
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