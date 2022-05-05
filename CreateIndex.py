# !/usr/bin/env python3 
# coding: utf-8
""" 
readme 生成 github page 的脚本 by LK233
"""

import re

prefix_url = "https://github.com/liangkang233/leetcode-cpp/blob/main/"
# **[array , hash table]**

def main():
    """
    JumpCpp     修改 跳转cpp 乱码超链接 转为 github 页面查看
    changeTag   修改 tag 标签 防止生成表格
    """
    lines = []
    with open('README.md', 'r', encoding='utf-8') as o_config :
        lines = o_config.readlines()
        i = 0
        for line in lines:
            temp = line.split()
            if(len(temp) > 1 and i > 10): # 省去开头10行表格 和 长度过短的
                lines[i] = re.sub(r' \| ', ' , ', lines[i])
                lines[i] = re.sub(r'\.\/', prefix_url, lines[i])
                # print(line)
            i += 1

    with open('./docs/index.md','w', encoding='utf-8') as new_nodes :   
        new_nodes.writelines(lines)
    

if __name__ == "__main__":
    main()