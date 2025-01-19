import re

cookies_txt = input()
cookies_dict = dict(re.findall(r'([^=;\s]+)=([^;]+)', cookies_txt))

print(cookies_dict)