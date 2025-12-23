### How to build
This workspace uses bazel WORKSPACE for dependency management. But from bazel 8 its going to be deprecated and use module
This needs to be upgrade to bazel module.
You can use though by adding two flag `--enable_workspace` and `--noenable_bzmod`
- Example: `bazel test  --enable_workspace --noenable_bzlmod //main/tests:time_utils_test`

## Updates
- Upgrade dependency to bazel module. Hence no need to use `--enable_workspace` and `--noenable_bzmod` flags. 
- For debug build : `bazel build -c dbg --strip=never  //main/tests:algo_test`