load ("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "main",
    srcs =["srcs/moderncpp.cpp"],
    deps =["//lib:print_utils"],
    visibility = ["//main:__subpackages__"]
)
