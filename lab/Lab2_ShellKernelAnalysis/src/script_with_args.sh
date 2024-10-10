#!/bin/bash

# 定义统计 .c 文件数量和大小的函数
count_c_files() {
    c_count=$(find ./linux-6.11.2 -name "*.c" | wc -l)
    c_size=$(find ./linux-6.11.2 -name "*.c" -exec du -b {} + | awk '{sum+=$1} END {print sum}')
    echo ".c 文件数量: $c_count"
    echo ".c 文件总字节数: $c_size"
}

# 定义统计 Shell 文件数量的函数
count_shell_files() {
    shell_count=$(find ./linux-6.11.2 -name "*.sh" | wc -l)
    echo "Shell 脚本文件数量: $shell_count"
}

# 生成 Makefile 文件路径清单的函数
generate_makefile_paths() {
    find ./linux-6.11.2 -name "Makefile" | sort > MakefilePathQD.txt
    echo "Makefile 文件路径清单已生成：MakefilePathQD.txt"
}

# 根据命令行参数调用对应的函数
case $1 in
    "count_c")
        count_c_files
        ;;
    "count_shell")
        count_shell_files
        ;;
    "generate_makefile")
        generate_makefile_paths
        ;;
    *)
        echo "使用方法: $0 {count_c|count_shell|generate_makefile}"
        exit 1
        ;;
esac
