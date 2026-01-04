cc_test(
    name = "time_utils_test",
    srcs = ["time_utils_test.cpp"],
    deps = ["//lib:time-utils",
           "@googletest//:gtest_main"],
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
           "@googletest//:gtest_main"],
    copts = ["-Ilib/includes"],
    data = [":test_data"],
)

cc_test(
    name = "data_structures_test",
    srcs =["data_structures_test.cpp"],
    deps =["//lib:data-structures",
           "@googletest//:gtest_main"],
    copts = ["-Ilib/includes"],

)

cc_test(
    name = "algo_test", 
    srcs = ["test_custom_array.cpp", "test_linked_list.cpp"],
    deps = ["//lib:algos",
            "//lib:print_utils",
         "@googletest//:gtest_main"],
    copts = ["-Ilib/includes",
    "-Iexternal/gtest/googletest/include",
    "-Iexternal/gtest/googletest",
    ],
)