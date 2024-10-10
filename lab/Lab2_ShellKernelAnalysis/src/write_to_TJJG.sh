#!/bin/bash

# 输出 .c 文件数量和字节数
echo ".c 文件数量: $(find ./linux-6.11.2 -name "*.c" | wc -l)" > TJJG.txt
echo ".c 文件总字节数: $(find ./linux-6.11.2 -name "*.c" -exec du -b {} + | awk '{sum+=$1} END {print sum}')" >> TJJG.txt

# 输出 .h 文件数量和字节数
echo ".h 文件数量: $(find ./linux-6.11.2 -name "*.h" | wc -l)" >> TJJG.txt
echo ".h 文件总字节数: $(find ./linux-6.11.2 -name "*.h" -exec du -b {} + | awk '{sum+=$1} END {print sum}')" >> TJJG.txt

# 输出 Makefile 文件数量和字节数
echo "Makefile 文件数量: $(find ./linux-6.11.2 -name "Makefile" | wc -l)" >> TJJG.txt
echo "Makefile 文件总字节数: $(find ./linux-6.11.2 -name "Makefile" -exec du -b {} + | awk '{sum+=$1} END {print sum}')" >> TJJG.txt

# 输出 .s 文件数量和字节数
echo ".s 文件数量: $(find ./linux-6.11.2 -name "*.s" | wc -l)" >> TJJG.txt
echo ".s 文件总字节数: $(find ./linux-6.11.2 -name "*.s" -exec du -b {} + | awk '{sum+=$1} END {print sum}')" >> TJJG.txt

# 输出 .S 文件数量和字节数
echo ".S 文件数量: $(find ./linux-6.11.2 -name "*.S" | wc -l)" >> TJJG.txt
echo ".S 文件总字节数: $(find ./linux-6.11.2 -name "*.S" -exec du -b {} + | awk '{sum+=$1} END {print sum}')" >> TJJG.txt

# 输出 Shell 脚本文件数量
echo "Shell 脚本文件数量: $(find ./linux-6.11.2 -name "*.sh" | wc -l)" >> TJJG.txt
