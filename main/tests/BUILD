cc_test(
    name = "time_utils_test",
    srcs = ["time_utils_test.cpp"],
    deps = ["//lib:time-utils",
           "@com_google_googletest//:gtest_main"],
    copts = ["-Ilib/includes"],
)

filegroup(
    name = "test_data",
    srcs = ["data/random_text.txt"]
)

cc_test(
    name = "input_utils_test",
    srcs = ["input_utils_test.cpp"],
    deps = ["//lib:input-utils",
            "//lib:algos",
            "//lib:print_utils",
           "@com_google_googletest//:gtest_main"],
    copts = ["-Ilib/includes"],
    data = [":test_data"],
)

cc_test(
    name = "data_structures_test",
    srcs =["data_structures_test.cpp"],
    deps =["//lib:data-structures",
           "@com_google_googletest//:gtest_main"],
    copts = ["-Ilib/includes"],

)