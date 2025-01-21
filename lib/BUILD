load ("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "print_utils",
    hdrs = ["includes/print_utils.hpp"],
    copts = ["-Ilib/includes"],
    visibility = ["//main:__subpackages__", 
    "//lib:__subpackages__"],
)

cc_library(
    name = "time-utils", 
    srcs = ["srcs/get_time.cpp"],
    hdrs = ["includes/get_time.hpp"],
    copts = ["-Ilib/includes"],
    visibility = ["//main:__subpackages__"],
)

cc_library(
    name = "input-utils",
    srcs =["srcs/input_utils.cpp"],
    hdrs = ["includes/input_utils.hpp"],
    copts = ["-Ilib/includes"],
    visibility = ["//main:__subpackages__"],
)
cc_library(
    name = "algos",
    hdrs = [ "includes/sort_algos.hpp"],
    copts = ["-Ilib/includes"],
    visibility = ["//main:__subpackages__"],
)

cc_library(
    name = "data-structures",
    hdrs = [ "includes/stacks_queues.hpp", 
     "includes/circular_buffer.hpp"],
    copts = ["-Ilib/includes"],
    visibility = ["//main:__subpackages__"],
)

cc_library(
    name = "string-utils",
    srcs = [ "srcs/string_utils.cpp"], 
    hdrs = ["includes/string_utils.hpp"],
    copts = ["-Ilib/includes"],
    visibility = ["//main:__subpackages__"],
)

