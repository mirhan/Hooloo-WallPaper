#!/usr/bin/python
# -*- coding: UTF-8 -*-

import string
import re

all_s = u''' 《约定 (Live)》歌词：
还记得当天旅馆的门牌 
还留住笑著离开的神态 
当天整个城市 那样轻快 
沿路一起走半哩长街 
还记得街灯照出一脸黄 
还燃亮那份微温的便档 
剪影的你轮廓太好看 
凝住眼泪才敢细看 
忘掉天地 彷佛也想不起自己 
仍未忘相约看漫天黄叶远飞 
就算会与你分离 凄绝的戏 
要决心忘记我便记不起 
明日天地 只恐怕认不出自己 
仍未忘跟你约定假如没有死 
就算你壮阔胸膛 不敌天气 
两鬓斑白都可认得你 
还记得当天吉他的和弦 
还明白每段旋律的伏线 
当天街角流过你声线 
沿路旅程如歌褪变 
就算你壮阔胸膛 不敌天气 
两鬓斑白都可认得你'''

comment_s = u'''剪影的你轮廓太好看''' 

def get_pure_string(s):
    re_u = re.findall(ur"[\u4e00-\u9fa5]|[\w']+", s)
    new_s = u""
    for x in re_u:
        new_s = new_s + x
    return new_s

###
def get_longest_common_string(string1, string2):
    if (len(string1) < len(string2)):
        tmp = string1
        string1 = string2
        string2 = tmp

    string2 = string2 + 'a'

    answer = ""
    len1, len2 = len(string1), len(string2)
    for i in range(len1):
        match = ""
        for j in range(len2):
            if (i + j < len1 and string1[i + j] == string2[j]):
                match += string2[j]
            else:
                if (len(match) > len(answer)): 
                    answer = match

                match = ""
    return answer

def main():
    a = get_pure_string(all_s)    
    # print "a =", a.encode("utf-8")
    b = get_pure_string(comment_s)   
    # print "b =", b.encode("utf-8") 
    c = get_longest_common_string(a, b)
    print "c =", c.encode("utf-8") 


###

main()





