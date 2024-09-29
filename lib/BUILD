load ("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "time-utils", 
    srcs = ["srcs/get_time.cpp"],
    hdrs = ["includes/get_time.hpp"],
    copts = ["-Ilib/includes"],
    visibility = ["//main:__subpackages__"],
)